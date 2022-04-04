using System.Windows;
using System.Windows.Media;
using Microsoft.Phone.Controls;

namespace MP_L4_T2
{
    public partial class MainPage : PhoneApplicationPage
    {
        private Brush errorBrush, correctBrush;
        
        public MainPage()
        {
            InitializeComponent();
            errorBrush = new SolidColorBrush(Colors.Green);
            correctBrush = OperandA.Foreground;
        }

        private void BtnGo_Click(object sender, RoutedEventArgs e) { calculate(); }

        private void calculate()
        {
            float v1, v2;

            if (!float.TryParse(OperandA.Text, out v1))
            {
                OperandA.Foreground = errorBrush;
                Result.Text = "Ошибка при вводе";
                return;
            }
            else OperandA.Foreground = correctBrush;
            if (!float.TryParse(OperandB.Text, out v2))
            {
                OperandB.Foreground = errorBrush;
                Result.Text = "Ошибка при вводе";
                return;
            }
            else OperandB.Foreground = correctBrush;

            float result = v1 + v2;
            Result.Text = result.ToString();
        }
    }
}