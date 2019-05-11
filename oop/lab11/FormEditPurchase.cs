using System;
using System.Windows.Forms;

namespace OOP_lab11
{
    public partial class FormEditPurchase : Form
    {
        public FormEditPurchase()
        {
            InitializeComponent();
        }

        private void logPurchaseBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            Validate();
            logPurchaseBindingSource.EndEdit();
            tableAdapterManager.UpdateAll(storeDBDataSet);
        }

        private void FormEditPurchase_Load(object sender, EventArgs e)
        {
            productsTableAdapter.Fill(storeDBDataSet.Products);
            logPurchaseTableAdapter.Fill(storeDBDataSet.LogPurchase);
        }
    }
}
