using System;
using System.Windows.Forms;

namespace OOP_lab11
{
    public partial class FormEditProducts : Form
    {
        public FormEditProducts()
        {
            InitializeComponent();
        }

        private void productsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            Validate();
            productsBindingSource.EndEdit();
            tableAdapterManager.UpdateAll(storeDBDataSet);
        }

        private void FormEditProducts_Load(object sender, EventArgs e)
        {
            productsTableAdapter.Fill(storeDBDataSet.Products);
        }
    }
}
