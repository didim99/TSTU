using System.ComponentModel;
using System.Windows;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using System;

namespace MP_L4_T5
{
    public partial class EditPage : PhoneApplicationPage
    {
        private MeeteingView view;

        public EditPage()
        {
            view = new MeeteingView();
            InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            App thisApp = Application.Current as App;
            view.Load(thisApp.ActiveMeeting);
            ContentPanel.DataContext = view;
        }

        protected override void OnBackKeyPress(CancelEventArgs e)
        {
            base.OnBackKeyPress(e);
            MessageBoxResult res = MessageBox.Show(
                "Вы действительно хотите покинуть страницу?",
            "Подтверждение перехода", MessageBoxButton.OKCancel);
            if (res != MessageBoxResult.OK) e.Cancel = true;
            else
            {
                App thisApp = Application.Current as App;
                thisApp.ActiveMeeting = null;
                NavigationService.GoBack();
            }
        }

        private void ClickSave(object sender, RoutedEventArgs e)
        {
            try
            {
                App thisApp = Application.Current as App;
                view.Save(thisApp.ActiveMeeting);
                NavigationService.GoBack();
            }
            catch (ArgumentException ex)
            {
                string err = "";
                switch (ex.Message)
                {
                    case "Invalid grade":
                        err = "Некорректно указана оценка.\nУкажите значение от 1 до 5";
                        break;
                    case "Invalid interval":
                        err = "Время окончания должно быть больше времени начала";
                        break;
                }

                MessageBox.Show(err, "Ошибка", MessageBoxButton.OK);
            }
            catch (FormatException)
            {
                MessageBox.Show("Некорректный формат времени.\nВведите время в формате ЧЧ:ММ", "Ошибка", MessageBoxButton.OK);
            }
        }

        private void ClickBack(object sender, RoutedEventArgs e)
        {
            OnBackKeyPress(new CancelEventArgs(false));
        }
    }
}