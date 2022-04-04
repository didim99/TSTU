namespace MP_L4_T4
{
    public class Customer
    {
        public string Surname { get; set; }
        public string Name { get; set; }
        public string Address { get; set; }
        public int ID { get; set; }

        public Customer(string inName, string inSurname,
                        string inAddress, int inID)
        {
            Surname = inSurname;
            Name = inName;
            Address = inAddress;
            ID = inID;
        }
    }
}
