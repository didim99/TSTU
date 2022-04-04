using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using Microsoft.Phone.Controls;

namespace MP_L4_T3
{
    public partial class MainPage : PhoneApplicationPage
    {
        private Brush errorBrush, correctBrush;
        private string operandA, operandB;

        public MainPage()
        {
            InitializeComponent();
            errorBrush = new SolidColorBrush(Colors.Green);
            correctBrush = OperandA.Foreground;
        }

        private void BtnGo_Click(object sender, RoutedEventArgs e) { calculate(); }

        private void OperandA_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (OperandA.Text == operandA) return;
            calculate();
        }

        private void OperandB_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (OperandB.Text == operandB) return;
            calculate();
        }

        private void calculate()
        {
            float v1, v2;
            operandA = OperandA.Text;
            operandB = OperandB.Text;
            if (operandA == "") operandA = "0";
            if (operandB == "") operandB = "0";

            if (!float.TryParse(operandA, out v1))
            {
                handreError(OperandA);
                return;
            }
            else OperandA.Foreground = correctBrush;
            if (!float.TryParse(operandB, out v2))
            {
                handreError(OperandB);
                return;
            }
            else OperandB.Foreground = correctBrush;

            float result = v1 + v2;
            Result.Text = result.ToString();
        }

        private void handreError(TextBox target)
        {
            target.Foreground = errorBrush;
            Result.Text = "Ошибка при вводе";
            MessageBoxResult res = MessageBox.Show(
                "Недопустимый ввод\nОчистить поле ввода?",
                "Ошибка", MessageBoxButton.OKCancel);
            if (res == MessageBoxResult.OK) target.Text = "";
        }
    }
}