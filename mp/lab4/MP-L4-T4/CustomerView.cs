using System.ComponentModel;

namespace MP_L4_T4
{
    public class CustomerView : INotifyPropertyChanged
    {
        private string surname;
        public string Surname
        {
            get { return surname; }
            set
            {
                surname = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("surname"));
            }
        }

        private string name;
        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("name"));
            }
        }

        private string address;
        public string Address
        {
            get { return address; }
            set
            {
                address = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("address"));
            }
        }

        private int id;
        public int ID { get { return id; } }

        public event PropertyChangedEventHandler PropertyChanged;

        public void Load(Customer cust)
        {
            Surname = cust.Surname;
            Name = cust.Name;
            Address = cust.Address;
            id = cust.ID;
        }

        public void Save(Customer cust)
        {
            cust.ID = ID;
            cust.Surname = Surname;
            cust.Name = Name;
            cust.Address = Address;
        }
    }
}
