using System;
using System.Drawing;
using System.Windows.Forms;

namespace OOP_lab11
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
            CenterToScreen();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            RefreshDataView();
            FilterColumn.SelectedIndex = 0;
        }

        private void BtnEditProducts_Click(object sender, EventArgs e)
        {
            EditDialog(new FormEditProducts());
        }

        private void BtnEditClients_Click(object sender, EventArgs e)
        {
            EditDialog(new FormEditClients());
        }

        private void BtnEditComission_Click(object sender, EventArgs e)
        {
            EditDialog(new FormEditComission());
        }

        private void BtnEditSale_Click(object sender, EventArgs e)
        {
            EditDialog(new FormEditSale());
        }

        private void BtnEditPurchase_Click(object sender, EventArgs e)
        {
            EditDialog(new FormEditPurchase());
        }

        private void EditDialog(Form form)
        {
            Point p = new Point(new Size(Location));
            p.Offset(30, 60);
            form.Location = p;
            form.ShowDialog(this);
            RefreshDataView();
        }

        private void RefreshDataView()
        {
            productsTableAdapter.Fill(storeDBDataSet.Products);
            clientsTableAdapter.Fill(storeDBDataSet.Clients);
            comissionTableAdapter.Fill(storeDBDataSet.Comission);
            logPurchaseTableAdapter.Fill(storeDBDataSet.LogPurchase);
            logSaleTableAdapter.Fill(storeDBDataSet.LogSale);
        }

        private void BtnFilter_Click(object sender, EventArgs e)
        {
            string column = "";
            switch (FilterColumn.SelectedIndex)
            {
                case 0: column = "ClientName"; break;
                case 1: column = "ProductName"; break;
                default: return;
            }

            string value = FilterValue.Text;
            comissionBindingSource.Filter = column + " LIKE '%" + value + "%'";
        }

        private void BtnClearFilter_Click(object sender, EventArgs e)
        {
            comissionBindingSource.Filter = null;
        }
    }
}
