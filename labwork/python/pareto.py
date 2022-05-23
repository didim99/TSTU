from enum import Enum
from typing import List, Union

"""
    Шапка CSV: DX,FX,...,FR-,DR+,...
        D: целое число
        F: дробное число
        X: переменная
        R: критерий
        +: ищем максимум по критерию
        -: ищем минимум по критерию
    
    Исходные данные положить в файл input.csv
    Выходные данные в файле output.csv
    
    ПРИМЕР CSV:
        DX,DX,DR-,FR+
        4,1,17,0.09 <-- лучше чем 2  будет удалена на втором шаге
        2,1,17,0.06                  будет удалена на первом шаге
        6,1,16,0.09 <-- лучше чем 1, на выходе останется только эта точка
"""


class DataType(Enum):
    Integer = 'D'
    Float = 'F'


class VarType(Enum):
    Var = 'X'
    Crit = 'R'


class ExtremaType(Enum):
    Min = '-'
    Max = '+'


class ColumnType(object):
    var: VarType
    num: DataType
    ext: ExtremaType

    def __init__(self, src: str):
        self.num = DataType(src[0])
        self.var = VarType(src[1])
        if self.var is VarType.Crit:
            self.ext = ExtremaType(src[2])

    def __repr__(self):
        res = self.num.value + self.var.value
        if self.var is VarType.Crit:
            res += self.ext.value
        return res


def mapper(var: tuple, types: List[ColumnType]) -> Union[int, float]:
    """Преобразование значения из CSV в число согласно типу данных в заголовке"""
    return int(var[1]) if types[var[0]].num is DataType.Integer else float(var[1])


def readall(path: str, separator: str) -> (List[ColumnType], List[tuple]):
    """Считать заголовок и данные из файла"""
    infile = open(path, 'r')

    header = infile.readline().strip().split(separator)
    types = list(map(lambda i: ColumnType(i), header))
    data = []

    for line in infile.readlines():
        line = line.strip().split(separator)
        line = tuple(map(lambda i: mapper(i, types), enumerate(line)))
        data.append(line)

    infile.close()
    return types, data


def writeall(path: str, separator: str, data: List[tuple]) -> None:
    """Записать заголовок и данные в файл"""
    outfile = open(path, 'w')

    for line in data:
        line = separator.join(list(map(lambda s: str(s), line)))
        outfile.write(line + "\n")

    outfile.close()


def better(types: List[ColumnType], bad: tuple, good: tuple) -> bool:
    """Лучше ли точка good чем точка bad"""
    maybe = False

    for i, ct in enumerate(types):
        # Если это переменная -- проходим мимо
        if ct.var is VarType.Var:
            continue

        # Если ищем максимум критерия
        if ct.ext is ExtremaType.Max:
            # Если хотя бы один критерий меньше -- не лучше
            if good[i] < bad[i]:
                return False
            # Если хотя бы один критерий больше -- возможно лучше
            if good[i] > bad[i]:
                maybe = True
        # Если ищем минимум критерия
        else:
            # Если хотя бы один критерий больше -- не лучше
            if good[i] > bad[i]:
                return False
            # Если хотя бы один критерий меньше -- возможно лучше
            if good[i] < bad[i]:
                maybe = True

    return maybe


def calculate(types: List[ColumnType], data: List[tuple]) -> List[tuple]:
    """Найти область Парето среди заданных точек методом полного перебора"""
    all_good = -1
    bad_point = 0

    # Пока есть хотя бы одна плохая точка
    while bad_point != all_good:
        bad_point = all_good

        for i, point1 in enumerate(data):
            # Если нашли плохую точку -- начинаем заново
            if bad_point != all_good:
                break

            for point2 in data:
                # Если точка 1 плохая -- помечаем для удаления и выходим из цикла
                if better(types, point1, point2):
                    print(point2, 'лучше чем', point1, sep=' ')
                    bad_point = i
                    break
                else:
                    print(point2, 'НЕ лучше чем', point1, sep=' ')

        if bad_point != all_good:
            del data[bad_point]

    return data


def start():
    infile = 'input.csv'
    outfile = 'output.csv'
    separator = ','

    types, data = readall(infile, separator)
    data = calculate(types, data)
    writeall(outfile, separator, [tuple(types), *data])


if __name__ == '__main__':
    start()
