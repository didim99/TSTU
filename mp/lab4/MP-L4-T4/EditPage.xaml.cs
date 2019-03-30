using System.ComponentModel;
using System.Windows;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;

namespace MP_L4_T4
{
    public partial class EditPage : PhoneApplicationPage
    {
        private CustomerView view = new CustomerView();

        public EditPage()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            App thisApp = Application.Current as App;
            view.Load(thisApp.ActiveCustomer);
            ContentPanel.DataContext = view;
        }

        protected override void OnBackKeyPress(CancelEventArgs e)
        {
            base.OnBackKeyPress(e);
            MessageBoxResult res = MessageBox.Show(
                "Вы действительно хотите перейти на другую страницу?",
            "Подтверждение перехода", MessageBoxButton.OKCancel);
            if (res != MessageBoxResult.OK) e.Cancel = true;
            else NavigationService.GoBack();
        }

        private void ClickSave(object sender, RoutedEventArgs e)
        {
            App thisApp = Application.Current as App;
            view.Save(thisApp.ActiveCustomer);
            NavigationService.GoBack();
        }

        private void ClickBack(object sender, RoutedEventArgs e)
        {
            OnBackKeyPress(new CancelEventArgs(false));
        }
    }
}