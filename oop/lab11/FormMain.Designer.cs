namespace OOP_lab11
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.BtnEditProducts = new System.Windows.Forms.Button();
            this.BtnEditClients = new System.Windows.Forms.Button();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.productsDataGridView = new System.Windows.Forms.DataGridView();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.clientsDataGridView = new System.Windows.Forms.DataGridView();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.BtnEditComission = new System.Windows.Forms.Button();
            this.comissionDataGridView = new System.Windows.Forms.DataGridView();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.logSaleDataGridView = new System.Windows.Forms.DataGridView();
            this.BtnEditSale = new System.Windows.Forms.Button();
            this.logPurchaseDataGridView = new System.Windows.Forms.DataGridView();
            this.label4 = new System.Windows.Forms.Label();
            this.BtnEditPurchase = new System.Windows.Forms.Button();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.productsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.storeDBDataSet = new OOP_lab11.StoreDBDataSet();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clientsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.comissionBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.logPurchaseBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.logSaleBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.clientsTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ClientsTableAdapter();
            this.tableAdapterManager = new OOP_lab11.StoreDBDataSetTableAdapters.TableAdapterManager();
            this.productsTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ProductsTableAdapter();
            this.comissionTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ComissionTableAdapter();
            this.logSaleTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.LogSaleTableAdapter();
            this.logPurchaseTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.LogPurchaseTableAdapter();
            this.dataGridViewTextBoxColumn9 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn10 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn15 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn14 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn16 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn19 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn18 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn11 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn13 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn12 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.FilterColumn = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.FilterValue = new System.Windows.Forms.TextBox();
            this.BtnFilter = new System.Windows.Forms.Button();
            this.BtnClearFilter = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.productsDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsDataGridView)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.comissionDataGridView)).BeginInit();
            this.tabPage3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.logSaleDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.productsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.storeDBDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.comissionBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.logSaleBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // BtnEditProducts
            // 
            this.BtnEditProducts.Location = new System.Drawing.Point(3, 319);
            this.BtnEditProducts.Name = "BtnEditProducts";
            this.BtnEditProducts.Size = new System.Drawing.Size(353, 37);
            this.BtnEditProducts.TabIndex = 0;
            this.BtnEditProducts.Text = "Редактировать";
            this.BtnEditProducts.UseVisualStyleBackColor = true;
            this.BtnEditProducts.Click += new System.EventHandler(this.BtnEditProducts_Click);
            // 
            // BtnEditClients
            // 
            this.BtnEditClients.Location = new System.Drawing.Point(362, 319);
            this.BtnEditClients.Name = "BtnEditClients";
            this.BtnEditClients.Size = new System.Drawing.Size(414, 37);
            this.BtnEditClients.TabIndex = 0;
            this.BtnEditClients.Text = "Редактировать";
            this.BtnEditClients.UseVisualStyleBackColor = true;
            this.BtnEditClients.Click += new System.EventHandler(this.BtnEditClients_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(787, 388);
            this.tabControl1.TabIndex = 1;
            // 
            // tabPage1
            // 
            this.tabPage1.AutoScroll = true;
            this.tabPage1.Controls.Add(this.productsDataGridView);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.clientsDataGridView);
            this.tabPage1.Controls.Add(this.BtnEditProducts);
            this.tabPage1.Controls.Add(this.BtnEditClients);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(779, 359);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Справочники";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // productsDataGridView
            // 
            this.productsDataGridView.AllowUserToAddRows = false;
            this.productsDataGridView.AllowUserToDeleteRows = false;
            this.productsDataGridView.AutoGenerateColumns = false;
            this.productsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.productsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7});
            this.productsDataGridView.DataSource = this.productsBindingSource;
            this.productsDataGridView.Location = new System.Drawing.Point(3, 29);
            this.productsDataGridView.Name = "productsDataGridView";
            this.productsDataGridView.ReadOnly = true;
            this.productsDataGridView.RowHeadersVisible = false;
            this.productsDataGridView.RowTemplate.Height = 24;
            this.productsDataGridView.Size = new System.Drawing.Size(353, 284);
            this.productsDataGridView.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(3, 3);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(353, 23);
            this.label2.TabIndex = 3;
            this.label2.Text = "Изделия";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(359, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(417, 23);
            this.label1.TabIndex = 3;
            this.label1.Text = "Клиенты";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // clientsDataGridView
            // 
            this.clientsDataGridView.AllowUserToAddRows = false;
            this.clientsDataGridView.AllowUserToDeleteRows = false;
            this.clientsDataGridView.AllowUserToResizeRows = false;
            this.clientsDataGridView.AutoGenerateColumns = false;
            this.clientsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.clientsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4});
            this.clientsDataGridView.DataSource = this.clientsBindingSource;
            this.clientsDataGridView.Location = new System.Drawing.Point(362, 29);
            this.clientsDataGridView.Name = "clientsDataGridView";
            this.clientsDataGridView.ReadOnly = true;
            this.clientsDataGridView.RowHeadersVisible = false;
            this.clientsDataGridView.RowTemplate.Height = 24;
            this.clientsDataGridView.Size = new System.Drawing.Size(414, 284);
            this.clientsDataGridView.TabIndex = 2;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.FilterValue);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.FilterColumn);
            this.tabPage2.Controls.Add(this.BtnClearFilter);
            this.tabPage2.Controls.Add(this.BtnFilter);
            this.tabPage2.Controls.Add(this.BtnEditComission);
            this.tabPage2.Controls.Add(this.comissionDataGridView);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(779, 359);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Журнал комиссии";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // BtnEditComission
            // 
            this.BtnEditComission.Location = new System.Drawing.Point(6, 316);
            this.BtnEditComission.Name = "BtnEditComission";
            this.BtnEditComission.Size = new System.Drawing.Size(554, 39);
            this.BtnEditComission.TabIndex = 1;
            this.BtnEditComission.Text = "Редактировать";
            this.BtnEditComission.UseVisualStyleBackColor = true;
            this.BtnEditComission.Click += new System.EventHandler(this.BtnEditComission_Click);
            // 
            // comissionDataGridView
            // 
            this.comissionDataGridView.AllowUserToAddRows = false;
            this.comissionDataGridView.AllowUserToDeleteRows = false;
            this.comissionDataGridView.AllowUserToResizeRows = false;
            this.comissionDataGridView.AutoGenerateColumns = false;
            this.comissionDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.comissionDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn8,
            this.dataGridViewTextBoxColumn11,
            this.dataGridViewTextBoxColumn13,
            this.dataGridViewTextBoxColumn12});
            this.comissionDataGridView.DataSource = this.comissionBindingSource;
            this.comissionDataGridView.Location = new System.Drawing.Point(6, 6);
            this.comissionDataGridView.Name = "comissionDataGridView";
            this.comissionDataGridView.ReadOnly = true;
            this.comissionDataGridView.RowHeadersVisible = false;
            this.comissionDataGridView.RowTemplate.Height = 24;
            this.comissionDataGridView.Size = new System.Drawing.Size(554, 306);
            this.comissionDataGridView.TabIndex = 0;
            // 
            // tabPage3
            // 
            this.tabPage3.AutoScroll = true;
            this.tabPage3.Controls.Add(this.label4);
            this.tabPage3.Controls.Add(this.logPurchaseDataGridView);
            this.tabPage3.Controls.Add(this.label3);
            this.tabPage3.Controls.Add(this.logSaleDataGridView);
            this.tabPage3.Controls.Add(this.BtnEditPurchase);
            this.tabPage3.Controls.Add(this.BtnEditSale);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(779, 359);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Журналы операций";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(0, 2);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(328, 23);
            this.label3.TabIndex = 4;
            this.label3.Text = "Выставление на продажу";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // logSaleDataGridView
            // 
            this.logSaleDataGridView.AllowUserToAddRows = false;
            this.logSaleDataGridView.AllowUserToDeleteRows = false;
            this.logSaleDataGridView.AutoGenerateColumns = false;
            this.logSaleDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.logSaleDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn9,
            this.dataGridViewTextBoxColumn10,
            this.dataGridViewTextBoxColumn15});
            this.logSaleDataGridView.DataSource = this.logSaleBindingSource;
            this.logSaleDataGridView.Location = new System.Drawing.Point(3, 28);
            this.logSaleDataGridView.Name = "logSaleDataGridView";
            this.logSaleDataGridView.ReadOnly = true;
            this.logSaleDataGridView.RowHeadersVisible = false;
            this.logSaleDataGridView.RowTemplate.Height = 24;
            this.logSaleDataGridView.Size = new System.Drawing.Size(325, 285);
            this.logSaleDataGridView.TabIndex = 1;
            // 
            // BtnEditSale
            // 
            this.BtnEditSale.Location = new System.Drawing.Point(3, 319);
            this.BtnEditSale.Name = "BtnEditSale";
            this.BtnEditSale.Size = new System.Drawing.Size(325, 37);
            this.BtnEditSale.TabIndex = 1;
            this.BtnEditSale.Text = "Редактировать";
            this.BtnEditSale.UseVisualStyleBackColor = true;
            this.BtnEditSale.Click += new System.EventHandler(this.BtnEditSale_Click);
            // 
            // logPurchaseDataGridView
            // 
            this.logPurchaseDataGridView.AllowUserToAddRows = false;
            this.logPurchaseDataGridView.AllowUserToDeleteRows = false;
            this.logPurchaseDataGridView.AutoGenerateColumns = false;
            this.logPurchaseDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.logPurchaseDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn14,
            this.dataGridViewTextBoxColumn16,
            this.dataGridViewTextBoxColumn19,
            this.dataGridViewTextBoxColumn18});
            this.logPurchaseDataGridView.DataSource = this.logPurchaseBindingSource;
            this.logPurchaseDataGridView.Location = new System.Drawing.Point(334, 28);
            this.logPurchaseDataGridView.Name = "logPurchaseDataGridView";
            this.logPurchaseDataGridView.ReadOnly = true;
            this.logPurchaseDataGridView.RowHeadersVisible = false;
            this.logPurchaseDataGridView.RowTemplate.Height = 24;
            this.logPurchaseDataGridView.Size = new System.Drawing.Size(442, 285);
            this.logPurchaseDataGridView.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(334, 2);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(442, 23);
            this.label4.TabIndex = 5;
            this.label4.Text = "Покупка";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // BtnEditPurchase
            // 
            this.BtnEditPurchase.Location = new System.Drawing.Point(334, 319);
            this.BtnEditPurchase.Name = "BtnEditPurchase";
            this.BtnEditPurchase.Size = new System.Drawing.Size(442, 37);
            this.BtnEditPurchase.TabIndex = 1;
            this.BtnEditPurchase.Text = "Редактировать";
            this.BtnEditPurchase.UseVisualStyleBackColor = true;
            this.BtnEditPurchase.Click += new System.EventHandler(this.BtnEditPurchase_Click);
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn5.HeaderText = "#";
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            this.dataGridViewTextBoxColumn5.ReadOnly = true;
            this.dataGridViewTextBoxColumn5.Width = 50;
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.DataPropertyName = "Name";
            this.dataGridViewTextBoxColumn6.HeaderText = "Наименование";
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            this.dataGridViewTextBoxColumn6.ReadOnly = true;
            this.dataGridViewTextBoxColumn6.Width = 200;
            // 
            // dataGridViewTextBoxColumn7
            // 
            this.dataGridViewTextBoxColumn7.DataPropertyName = "Price";
            this.dataGridViewTextBoxColumn7.HeaderText = "Цена";
            this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            this.dataGridViewTextBoxColumn7.ReadOnly = true;
            // 
            // productsBindingSource
            // 
            this.productsBindingSource.DataMember = "Products";
            this.productsBindingSource.DataSource = this.storeDBDataSet;
            // 
            // storeDBDataSet
            // 
            this.storeDBDataSet.DataSetName = "StoreDBDataSet";
            this.storeDBDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn1.HeaderText = "#";
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            this.dataGridViewTextBoxColumn1.Width = 50;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.DataPropertyName = "FirstName";
            this.dataGridViewTextBoxColumn2.HeaderText = "Имя";
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.ReadOnly = true;
            this.dataGridViewTextBoxColumn2.Width = 120;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.DataPropertyName = "LastName";
            this.dataGridViewTextBoxColumn3.HeaderText = "Фамилия";
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.ReadOnly = true;
            this.dataGridViewTextBoxColumn3.Width = 120;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.DataPropertyName = "Phone";
            this.dataGridViewTextBoxColumn4.HeaderText = "Телефон";
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            this.dataGridViewTextBoxColumn4.ReadOnly = true;
            this.dataGridViewTextBoxColumn4.Width = 120;
            // 
            // clientsBindingSource
            // 
            this.clientsBindingSource.DataMember = "Clients";
            this.clientsBindingSource.DataSource = this.storeDBDataSet;
            // 
            // comissionBindingSource
            // 
            this.comissionBindingSource.DataMember = "Comission";
            this.comissionBindingSource.DataSource = this.storeDBDataSet;
            // 
            // logPurchaseBindingSource
            // 
            this.logPurchaseBindingSource.DataMember = "LogPurchase";
            this.logPurchaseBindingSource.DataSource = this.storeDBDataSet;
            // 
            // logSaleBindingSource
            // 
            this.logSaleBindingSource.DataMember = "LogSale";
            this.logSaleBindingSource.DataSource = this.storeDBDataSet;
            // 
            // clientsTableAdapter
            // 
            this.clientsTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.ClientsTableAdapter = this.clientsTableAdapter;
            this.tableAdapterManager.ComissionTableAdapter = null;
            this.tableAdapterManager.LogPurchaseTableAdapter = null;
            this.tableAdapterManager.LogSaleTableAdapter = null;
            this.tableAdapterManager.ProductsTableAdapter = this.productsTableAdapter;
            this.tableAdapterManager.UpdateOrder = OOP_lab11.StoreDBDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // productsTableAdapter
            // 
            this.productsTableAdapter.ClearBeforeFill = true;
            // 
            // comissionTableAdapter
            // 
            this.comissionTableAdapter.ClearBeforeFill = true;
            // 
            // logSaleTableAdapter
            // 
            this.logSaleTableAdapter.ClearBeforeFill = true;
            // 
            // logPurchaseTableAdapter
            // 
            this.logPurchaseTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridViewTextBoxColumn9
            // 
            this.dataGridViewTextBoxColumn9.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn9.HeaderText = "#";
            this.dataGridViewTextBoxColumn9.Name = "dataGridViewTextBoxColumn9";
            this.dataGridViewTextBoxColumn9.ReadOnly = true;
            this.dataGridViewTextBoxColumn9.Width = 50;
            // 
            // dataGridViewTextBoxColumn10
            // 
            this.dataGridViewTextBoxColumn10.DataPropertyName = "Datetime";
            this.dataGridViewTextBoxColumn10.HeaderText = "Дата/время";
            this.dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
            this.dataGridViewTextBoxColumn10.ReadOnly = true;
            this.dataGridViewTextBoxColumn10.Width = 130;
            // 
            // dataGridViewTextBoxColumn15
            // 
            this.dataGridViewTextBoxColumn15.DataPropertyName = "ProductName";
            this.dataGridViewTextBoxColumn15.HeaderText = "Изделие";
            this.dataGridViewTextBoxColumn15.Name = "dataGridViewTextBoxColumn15";
            this.dataGridViewTextBoxColumn15.ReadOnly = true;
            this.dataGridViewTextBoxColumn15.Width = 140;
            // 
            // dataGridViewTextBoxColumn14
            // 
            this.dataGridViewTextBoxColumn14.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn14.HeaderText = "#";
            this.dataGridViewTextBoxColumn14.Name = "dataGridViewTextBoxColumn14";
            this.dataGridViewTextBoxColumn14.ReadOnly = true;
            this.dataGridViewTextBoxColumn14.Width = 50;
            // 
            // dataGridViewTextBoxColumn16
            // 
            this.dataGridViewTextBoxColumn16.DataPropertyName = "Datetime";
            this.dataGridViewTextBoxColumn16.HeaderText = "Дата/время";
            this.dataGridViewTextBoxColumn16.Name = "dataGridViewTextBoxColumn16";
            this.dataGridViewTextBoxColumn16.ReadOnly = true;
            this.dataGridViewTextBoxColumn16.Width = 130;
            // 
            // dataGridViewTextBoxColumn19
            // 
            this.dataGridViewTextBoxColumn19.DataPropertyName = "ProductName";
            this.dataGridViewTextBoxColumn19.HeaderText = "Изделие";
            this.dataGridViewTextBoxColumn19.Name = "dataGridViewTextBoxColumn19";
            this.dataGridViewTextBoxColumn19.ReadOnly = true;
            this.dataGridViewTextBoxColumn19.Width = 140;
            // 
            // dataGridViewTextBoxColumn18
            // 
            this.dataGridViewTextBoxColumn18.DataPropertyName = "OperationId";
            this.dataGridViewTextBoxColumn18.HeaderText = "Операция";
            this.dataGridViewTextBoxColumn18.Name = "dataGridViewTextBoxColumn18";
            this.dataGridViewTextBoxColumn18.ReadOnly = true;
            this.dataGridViewTextBoxColumn18.Width = 118;
            // 
            // dataGridViewTextBoxColumn8
            // 
            this.dataGridViewTextBoxColumn8.DataPropertyName = "Id";
            this.dataGridViewTextBoxColumn8.HeaderText = "#";
            this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
            this.dataGridViewTextBoxColumn8.ReadOnly = true;
            this.dataGridViewTextBoxColumn8.Width = 50;
            // 
            // dataGridViewTextBoxColumn11
            // 
            this.dataGridViewTextBoxColumn11.DataPropertyName = "Datetime";
            this.dataGridViewTextBoxColumn11.HeaderText = "Дата/время";
            this.dataGridViewTextBoxColumn11.Name = "dataGridViewTextBoxColumn11";
            this.dataGridViewTextBoxColumn11.ReadOnly = true;
            this.dataGridViewTextBoxColumn11.Width = 150;
            // 
            // dataGridViewTextBoxColumn13
            // 
            this.dataGridViewTextBoxColumn13.DataPropertyName = "ClientName";
            this.dataGridViewTextBoxColumn13.HeaderText = "Клиент";
            this.dataGridViewTextBoxColumn13.Name = "dataGridViewTextBoxColumn13";
            this.dataGridViewTextBoxColumn13.ReadOnly = true;
            this.dataGridViewTextBoxColumn13.Width = 200;
            // 
            // dataGridViewTextBoxColumn12
            // 
            this.dataGridViewTextBoxColumn12.DataPropertyName = "ProductName";
            this.dataGridViewTextBoxColumn12.HeaderText = "Изделие";
            this.dataGridViewTextBoxColumn12.Name = "dataGridViewTextBoxColumn12";
            this.dataGridViewTextBoxColumn12.ReadOnly = true;
            this.dataGridViewTextBoxColumn12.Width = 150;
            // 
            // FilterColumn
            // 
            this.FilterColumn.FormattingEnabled = true;
            this.FilterColumn.Items.AddRange(new object[] {
            "Клиент",
            "Изделие"});
            this.FilterColumn.Location = new System.Drawing.Point(615, 27);
            this.FilterColumn.Name = "FilterColumn";
            this.FilterColumn.Size = new System.Drawing.Size(158, 24);
            this.FilterColumn.TabIndex = 2;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(566, 30);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(42, 17);
            this.label5.TabIndex = 3;
            this.label5.Text = "Поле";
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(566, 6);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(207, 18);
            this.label6.TabIndex = 3;
            this.label6.Text = "Фильтр";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(567, 60);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(73, 17);
            this.label7.TabIndex = 3;
            this.label7.Text = "Содержит";
            // 
            // FilterValue
            // 
            this.FilterValue.Location = new System.Drawing.Point(646, 57);
            this.FilterValue.Name = "FilterValue";
            this.FilterValue.Size = new System.Drawing.Size(127, 22);
            this.FilterValue.TabIndex = 4;
            // 
            // BtnFilter
            // 
            this.BtnFilter.Location = new System.Drawing.Point(566, 85);
            this.BtnFilter.Name = "BtnFilter";
            this.BtnFilter.Size = new System.Drawing.Size(207, 39);
            this.BtnFilter.TabIndex = 1;
            this.BtnFilter.Text = "Применить";
            this.BtnFilter.UseVisualStyleBackColor = true;
            this.BtnFilter.Click += new System.EventHandler(this.BtnFilter_Click);
            // 
            // BtnClearFilter
            // 
            this.BtnClearFilter.Location = new System.Drawing.Point(566, 130);
            this.BtnClearFilter.Name = "BtnClearFilter";
            this.BtnClearFilter.Size = new System.Drawing.Size(207, 39);
            this.BtnClearFilter.TabIndex = 1;
            this.BtnClearFilter.Text = "Сбросить";
            this.BtnClearFilter.UseVisualStyleBackColor = true;
            this.BtnClearFilter.Click += new System.EventHandler(this.BtnClearFilter_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(787, 388);
            this.Controls.Add(this.tabControl1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "FormMain";
            this.ShowIcon = false;
            this.Text = "OOP lab11";
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.productsDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsDataGridView)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.comissionDataGridView)).EndInit();
            this.tabPage3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.logSaleDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.productsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.storeDBDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.clientsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.comissionBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.logSaleBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BtnEditProducts;
        private System.Windows.Forms.Button BtnEditClients;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private StoreDBDataSet storeDBDataSet;
        private System.Windows.Forms.BindingSource clientsBindingSource;
        private StoreDBDataSetTableAdapters.ClientsTableAdapter clientsTableAdapter;
        private StoreDBDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView clientsDataGridView;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private StoreDBDataSetTableAdapters.ProductsTableAdapter productsTableAdapter;
        private System.Windows.Forms.BindingSource productsBindingSource;
        private System.Windows.Forms.DataGridView productsDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn7;
        private System.Windows.Forms.BindingSource comissionBindingSource;
        private StoreDBDataSetTableAdapters.ComissionTableAdapter comissionTableAdapter;
        private System.Windows.Forms.Button BtnEditComission;
        private System.Windows.Forms.DataGridView comissionDataGridView;
        private System.Windows.Forms.Button BtnEditSale;
        private System.Windows.Forms.BindingSource logSaleBindingSource;
        private StoreDBDataSetTableAdapters.LogSaleTableAdapter logSaleTableAdapter;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DataGridView logSaleDataGridView;
        private System.Windows.Forms.BindingSource logPurchaseBindingSource;
        private StoreDBDataSetTableAdapters.LogPurchaseTableAdapter logPurchaseTableAdapter;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.DataGridView logPurchaseDataGridView;
        private System.Windows.Forms.Button BtnEditPurchase;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn11;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn13;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn12;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn14;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn16;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn19;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn18;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn9;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn10;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn15;
        private System.Windows.Forms.TextBox FilterValue;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox FilterColumn;
        private System.Windows.Forms.Button BtnClearFilter;
        private System.Windows.Forms.Button BtnFilter;
    }
}