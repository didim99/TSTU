using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using System.Xml.Serialization;
using Microsoft.Phone.Controls;
using Windows.Storage;

namespace MP_L4_T5
{
    public partial class MainPage : PhoneApplicationPage
    {
        private ObservableCollection<Meeting> observableMeetings;

        public MainPage()
        {
            InitializeComponent();
            observableMeetings = new ObservableCollection<Meeting>();
            ItemList.ItemsSource = observableMeetings;
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            ItemList.SelectedItem = null;
            App thisApp = Application.Current as App;
            Meeting m = thisApp.ActiveMeeting;
            if (m != null)
            {
                int pos = observableMeetings.IndexOf(m);
                if (pos >= 0)
                {
                    observableMeetings.RemoveAt(pos);
                    observableMeetings.Insert(pos, m);
                }
                else observableMeetings.Add(m);
            }
        }

        private void BtnAdd_Click(object sender, RoutedEventArgs e)
        {
            App thisApp = Application.Current as App;
            thisApp.ActiveMeeting = new Meeting();

            NavigationService.Navigate(new Uri("/EditPage.xaml", UriKind.Relative));
        }

        private async void BtnSave_Click(object sender, RoutedEventArgs e)
        {
            StorageFolder externalDevices = KnownFolders.RemovableDevices;
            StorageFolder sdCard = (await externalDevices.GetFoldersAsync()).FirstOrDefault();

            List<Meeting> list = observableMeetings.ToList();
            XmlSerializer serializer = new XmlSerializer(typeof(List<Meeting>));
            FileStream fs = new FileStream(sdCard.Name + "/meetingList.xml", FileMode.OpenOrCreate);
            serializer.Serialize(fs, list);
            MessageBox.Show("Данные сохранены в " + fs.Name);
        }

        private void ItemList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (ItemList.SelectedItem == null) return;
            Meeting m = ItemList.SelectedItem as Meeting;
            App thisApp = Application.Current as App;
            thisApp.ActiveMeeting = m;

            NavigationService.Navigate(new Uri("/EditPage.xaml", UriKind.Relative));
        }
    }
}