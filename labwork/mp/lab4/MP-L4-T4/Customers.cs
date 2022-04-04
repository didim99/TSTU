using System.Collections.Generic;

namespace MP_L4_T4
{
    public class Customers
    {
        public string Name { get; set; }
        public List<Customer> CustomerList;

        public Customers(string inName)
        {
            Name = inName;
            CustomerList = new List<Customer>();
        }

        public static Customers MakeTestCustomers()
        {
            string[] firstNames = new string[] { "Rob", "Jim", "Joe", "Nigel", "Sally", "Tim", "Don", "Kate" };
            string[] lastsNames = new string[] { "Smith", "Jones", "Bloggs", "Miles", "Wilkins", "Brown", "Jonson", "Rives" };
            Customers result = new Customers("Тестовый список");
            int id = 0;

            foreach (string lastName in lastsNames)
            {
                foreach (string firstname in firstNames)
                    result.CustomerList.Add(new Customer(firstname, lastName, firstname + "'s House", id++));
            }

            return result;
        }
    }
}
