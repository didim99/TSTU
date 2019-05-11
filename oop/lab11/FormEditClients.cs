using System;
using System.Windows.Forms;

namespace OOP_lab11
{
    public partial class FormEditClients : Form
    {
        public FormEditClients()
        {
            InitializeComponent();
        }

        private void clientsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            Validate();
            clientsBindingSource.EndEdit();
            tableAdapterManager.UpdateAll(storeDBDataSet);

        }

        private void FormEditClients_Load(object sender, EventArgs e)
        {
            clientsTableAdapter.Fill(storeDBDataSet.Clients);
        }
    }
}
