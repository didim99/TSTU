using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MP_L4_T1
{
    public class Account
    {
        private decimal balance;
        private string name;
        private int ageValue;

        public int Age
        {
            set { if ((value > 0) && (value < 120)) ageValue = value; }
            get { return ageValue; }
        }

        public int AgeInMonths
        {
            get { return this.ageValue * 12; }
        }

        public string GetName() { return name; }
        public int GetAge() { return this.ageValue; }

        public bool SetName(string newName)
        {
            // в финальной версии здесь можно проверить корректность имени 
            name = newName;
            return true;
        }

        public void SetAge(int inAge)
        {
            if ((inAge > 0) && (inAge < 120))
                this.ageValue = inAge;
        }
    }
}
