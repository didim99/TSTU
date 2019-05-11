using System;
using System.Windows.Forms;

namespace OOP_lab11
{
    public partial class FormEditComission : Form
    {
        public FormEditComission()
        {
            InitializeComponent();
        }

        private void comissionBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            Validate();
            comissionBindingSource.EndEdit();
            tableAdapterManager.UpdateAll(storeDBDataSet);
        }

        private void FormEditComission_Load(object sender, EventArgs e)
        {
            productsTableAdapter.Fill(storeDBDataSet.Products);
            clientsTableAdapter.Fill(storeDBDataSet.Clients);
            comissionTableAdapter.Fill(storeDBDataSet.Comission);
        }
    }
}
