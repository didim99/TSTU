import numpy as np


def sigma(_m):
    return 1.0 / (1.0 + np.exp(-_m))


def error_sqr(_y, _d):
    return 0.5 * (_y - _d) ** 2


def error_pd(_y, _d):
    return (_y - _d) * _y * (1 - _y)


if __name__ == "__main__":
    netIn = np.array([0.725, 0.7])
    netOut = 0.74

    net = [
        np.array([[0.1, 0.2],
                  [0.1, 0.2]]),
        np.array([[0.2], [0.1]])]

    te = 0.001
    e = 1.0

    it = 0
    while e > te:
        it += 1
        layerCache = []
        layerIn = netIn
        layerCache.append(layerIn)
        for layer in net:
            layerIn = sigma(layerIn @ layer)
            layerCache.append(layerIn)
        e = error_sqr(layerIn[0], netOut)
        print(it, e)
        target = np.array(netOut)
        for i in range(len(net) - 1, -1, -1):
            eq = error_pd(layerCache[i], target)
            eq = eq * layerCache[i - 1]
            if len(eq.shape) == 1:
                eq = eq.reshape((2, 1))
            net[i] -= eq
