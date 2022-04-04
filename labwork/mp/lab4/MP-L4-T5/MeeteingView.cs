using System.ComponentModel;

namespace MP_L4_T5
{
    class MeeteingView : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private string start;
        public string TStart
        {
            get { return start; }
            set
            {
                start = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("start"));
            }
        }

        private string end;
        public string TEnd
        {
            get { return end; }
            set
            {
                end = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("end"));
            }
        }

        private string company;
        public string Company
        {
            get { return company; }
            set
            {
                company = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("company"));
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

        private int grade;
        public int Grade
        {
            get { return grade; }
            set
            {
                grade = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("grade"));
            }
        }

        public void Load(Meeting m)
        {
            TStart = m.TStart;
            TEnd = m.TEnd;
            Company = m.Company;
            Address = m.Address;
            Grade = m.Grade;
        }

        public void Save(Meeting m)
        {
            m.TStart = TStart;
            m.TEnd = TEnd;
            m.Company = Company;
            m.Address = Address;
            m.Grade = Grade;
        }
    }
}
