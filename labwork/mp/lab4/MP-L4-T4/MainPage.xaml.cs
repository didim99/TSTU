using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using MP_L4_T4.Resources;

namespace MP_L4_T4
{
    public partial class MainPage : PhoneApplicationPage
    {
        private ObservableCollection<Customer> observableCustomers;

        public MainPage()
        {
            InitializeComponent();
            App thisApp = Application.Current as App;
            observableCustomers = new ObservableCollection<Customer>(thisApp.ActiveCustomerList.CustomerList);
            CustomerList.ItemsSource = observableCustomers;
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            CustomerList.SelectedItem = null;
            App thisApp = Application.Current as App;
            Customer c = thisApp.ActiveCustomer;
            if (c != null)
            { 
                int pos = observableCustomers.IndexOf(c);
                observableCustomers.RemoveAt(pos);
                observableCustomers.Insert(pos, c);
                thisApp.ActiveCustomerList.CustomerList =
                    observableCustomers.ToList<Customer>();
            }
        }

        private void CustomerList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (CustomerList.SelectedItem == null) return;
            Customer c = CustomerList.SelectedItem as Customer;
            App thisApp = Application.Current as App;
            thisApp.ActiveCustomer = c;

            NavigationService.Navigate(new Uri("/EditPage.xaml", UriKind.Relative));
        }
    }
}