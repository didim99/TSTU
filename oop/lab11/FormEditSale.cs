using System;
using System.Windows.Forms;

namespace OOP_lab11
{
    public partial class FormEditSale : Form
    {
        public FormEditSale()
        {
            InitializeComponent();
        }

        private void logSaleBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            Validate();
            logSaleBindingSource.EndEdit();
            tableAdapterManager.UpdateAll(storeDBDataSet);
        }

        private void FormEditSale_Load(object sender, EventArgs e)
        {
            productsTableAdapter.Fill(storeDBDataSet.Products);
            logSaleTableAdapter.Fill(storeDBDataSet.LogSale);
        }
    }
}
