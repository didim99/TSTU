namespace OOP_lab11
{
    partial class FormEditComission
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
            System.Windows.Forms.Label idLabel;
            System.Windows.Forms.Label clientIdLabel;
            System.Windows.Forms.Label productIdLabel;
            System.Windows.Forms.Label datetimeLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormEditComission));
            this.storeDBDataSet = new OOP_lab11.StoreDBDataSet();
            this.comissionBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.comissionTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ComissionTableAdapter();
            this.tableAdapterManager = new OOP_lab11.StoreDBDataSetTableAdapters.TableAdapterManager();
            this.comissionBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
            this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
            this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
            this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.comissionBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.idLabel1 = new System.Windows.Forms.Label();
            this.clientIdComboBox = new System.Windows.Forms.ComboBox();
            this.clientsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.productIdComboBox = new System.Windows.Forms.ComboBox();
            this.productsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.datetimeDateTimePicker = new System.Windows.Forms.DateTimePicker();
            this.clientsTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ClientsTableAdapter();
            this.productsTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ProductsTableAdapter();
            idLabel = new System.Windows.Forms.Label();
            clientIdLabel = new System.Windows.Forms.Label();
            productIdLabel = new System.Windows.Forms.Label();
            datetimeLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.storeDBDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.comissionBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.comissionBindingNavigator)).BeginInit();
            this.comissionBindingNavigator.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.clientsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.productsBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // idLabel
            // 
            idLabel.AutoSize = true;
            idLabel.Location = new System.Drawing.Point(58, 42);
            idLabel.Name = "idLabel";
            idLabel.Size = new System.Drawing.Size(26, 17);
            idLabel.TabIndex = 1;
            idLabel.Text = "№:";
            idLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // clientIdLabel
            // 
            clientIdLabel.AutoSize = true;
            clientIdLabel.Location = new System.Drawing.Point(24, 71);
            clientIdLabel.Name = "clientIdLabel";
            clientIdLabel.Size = new System.Drawing.Size(60, 17);
            clientIdLabel.TabIndex = 3;
            clientIdLabel.Text = "Клиент:";
            clientIdLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // productIdLabel
            // 
            productIdLabel.AutoSize = true;
            productIdLabel.Location = new System.Drawing.Point(15, 102);
            productIdLabel.Name = "productIdLabel";
            productIdLabel.Size = new System.Drawing.Size(69, 17);
            productIdLabel.TabIndex = 5;
            productIdLabel.Text = "Изделие:";
            productIdLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // datetimeLabel
            // 
            datetimeLabel.AutoSize = true;
            datetimeLabel.Location = new System.Drawing.Point(38, 135);
            datetimeLabel.Name = "datetimeLabel";
            datetimeLabel.Size = new System.Drawing.Size(46, 17);
            datetimeLabel.TabIndex = 7;
            datetimeLabel.Text = "Дата:";
            datetimeLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // storeDBDataSet
            // 
            this.storeDBDataSet.DataSetName = "StoreDBDataSet";
            this.storeDBDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // comissionBindingSource
            // 
            this.comissionBindingSource.DataMember = "Comission";
            this.comissionBindingSource.DataSource = this.storeDBDataSet;
            // 
            // comissionTableAdapter
            // 
            this.comissionTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.ClientsTableAdapter = null;
            this.tableAdapterManager.ComissionTableAdapter = this.comissionTableAdapter;
            this.tableAdapterManager.LogPurchaseTableAdapter = null;
            this.tableAdapterManager.LogSaleTableAdapter = null;
            this.tableAdapterManager.ProductsTableAdapter = null;
            this.tableAdapterManager.UpdateOrder = OOP_lab11.StoreDBDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // comissionBindingNavigator
            // 
            this.comissionBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
            this.comissionBindingNavigator.BindingSource = this.comissionBindingSource;
            this.comissionBindingNavigator.CountItem = this.bindingNavigatorCountItem;
            this.comissionBindingNavigator.CountItemFormat = "из {0}";
            this.comissionBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
            this.comissionBindingNavigator.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.comissionBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.comissionBindingNavigatorSaveItem});
            this.comissionBindingNavigator.Location = new System.Drawing.Point(0, 0);
            this.comissionBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.comissionBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.comissionBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.comissionBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.comissionBindingNavigator.Name = "comissionBindingNavigator";
            this.comissionBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
            this.comissionBindingNavigator.Size = new System.Drawing.Size(298, 27);
            this.comissionBindingNavigator.TabIndex = 0;
            this.comissionBindingNavigator.Text = "bindingNavigator1";
            // 
            // bindingNavigatorAddNewItem
            // 
            this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
            this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
            this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(24, 24);
            this.bindingNavigatorAddNewItem.Text = "Добавить";
            // 
            // bindingNavigatorCountItem
            // 
            this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
            this.bindingNavigatorCountItem.Size = new System.Drawing.Size(47, 24);
            this.bindingNavigatorCountItem.Text = "из {0}";
            this.bindingNavigatorCountItem.ToolTipText = "Общее число элементов";
            // 
            // bindingNavigatorDeleteItem
            // 
            this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
            this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
            this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(24, 24);
            this.bindingNavigatorDeleteItem.Text = "Удалить";
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
            this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
            this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(24, 24);
            this.bindingNavigatorMoveFirstItem.Text = "Переместить в начало";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
            this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
            this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(24, 24);
            this.bindingNavigatorMovePreviousItem.Text = "Переместить назад";
            // 
            // bindingNavigatorSeparator
            // 
            this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 27);
            // 
            // bindingNavigatorPositionItem
            // 
            this.bindingNavigatorPositionItem.AccessibleName = "Положение";
            this.bindingNavigatorPositionItem.AutoSize = false;
            this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
            this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 27);
            this.bindingNavigatorPositionItem.Text = "0";
            this.bindingNavigatorPositionItem.ToolTipText = "Текущее положение";
            // 
            // bindingNavigatorSeparator1
            // 
            this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
            this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 27);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
            this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
            this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(24, 24);
            this.bindingNavigatorMoveNextItem.Text = "Переместить вперед";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
            this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
            this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(24, 24);
            this.bindingNavigatorMoveLastItem.Text = "Переместить в конец";
            // 
            // bindingNavigatorSeparator2
            // 
            this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
            this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 27);
            // 
            // comissionBindingNavigatorSaveItem
            // 
            this.comissionBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.comissionBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("comissionBindingNavigatorSaveItem.Image")));
            this.comissionBindingNavigatorSaveItem.Name = "comissionBindingNavigatorSaveItem";
            this.comissionBindingNavigatorSaveItem.Size = new System.Drawing.Size(24, 24);
            this.comissionBindingNavigatorSaveItem.Text = "Сохранить данные";
            this.comissionBindingNavigatorSaveItem.Click += new System.EventHandler(this.comissionBindingNavigatorSaveItem_Click);
            // 
            // idLabel1
            // 
            this.idLabel1.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.comissionBindingSource, "Id", true));
            this.idLabel1.Location = new System.Drawing.Point(90, 42);
            this.idLabel1.Name = "idLabel1";
            this.idLabel1.Size = new System.Drawing.Size(200, 23);
            this.idLabel1.TabIndex = 2;
            this.idLabel1.Text = "label1";
            // 
            // clientIdComboBox
            // 
            this.clientIdComboBox.DataBindings.Add(new System.Windows.Forms.Binding("SelectedValue", this.comissionBindingSource, "ClientId", true));
            this.clientIdComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.comissionBindingSource, "ClientName", true));
            this.clientIdComboBox.DataSource = this.clientsBindingSource;
            this.clientIdComboBox.DisplayMember = "FullName";
            this.clientIdComboBox.FormattingEnabled = true;
            this.clientIdComboBox.Location = new System.Drawing.Point(90, 68);
            this.clientIdComboBox.Name = "clientIdComboBox";
            this.clientIdComboBox.Size = new System.Drawing.Size(200, 24);
            this.clientIdComboBox.TabIndex = 4;
            this.clientIdComboBox.ValueMember = "Id";
            // 
            // clientsBindingSource
            // 
            this.clientsBindingSource.DataMember = "Clients";
            this.clientsBindingSource.DataSource = this.storeDBDataSet;
            // 
            // productIdComboBox
            // 
            this.productIdComboBox.DataBindings.Add(new System.Windows.Forms.Binding("SelectedValue", this.comissionBindingSource, "ProductId", true));
            this.productIdComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.comissionBindingSource, "ProductName", true));
            this.productIdComboBox.DataSource = this.productsBindingSource;
            this.productIdComboBox.DisplayMember = "Name";
            this.productIdComboBox.FormattingEnabled = true;
            this.productIdComboBox.Location = new System.Drawing.Point(90, 99);
            this.productIdComboBox.Name = "productIdComboBox";
            this.productIdComboBox.Size = new System.Drawing.Size(200, 24);
            this.productIdComboBox.TabIndex = 6;
            this.productIdComboBox.ValueMember = "Id";
            // 
            // productsBindingSource
            // 
            this.productsBindingSource.DataMember = "Products";
            this.productsBindingSource.DataSource = this.storeDBDataSet;
            // 
            // datetimeDateTimePicker
            // 
            this.datetimeDateTimePicker.CustomFormat = "dd.MM.yyyy HH:mm";
            this.datetimeDateTimePicker.DataBindings.Add(new System.Windows.Forms.Binding("Value", this.comissionBindingSource, "Datetime", true));
            this.datetimeDateTimePicker.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.datetimeDateTimePicker.Location = new System.Drawing.Point(90, 130);
            this.datetimeDateTimePicker.Name = "datetimeDateTimePicker";
            this.datetimeDateTimePicker.Size = new System.Drawing.Size(200, 22);
            this.datetimeDateTimePicker.TabIndex = 8;
            // 
            // clientsTableAdapter
            // 
            this.clientsTableAdapter.ClearBeforeFill = true;
            // 
            // productsTableAdapter
            // 
            this.productsTableAdapter.ClearBeforeFill = true;
            // 
            // FormEditComission
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(298, 161);
            this.Controls.Add(idLabel);
            this.Controls.Add(this.idLabel1);
            this.Controls.Add(clientIdLabel);
            this.Controls.Add(this.clientIdComboBox);
            this.Controls.Add(productIdLabel);
            this.Controls.Add(this.productIdComboBox);
            this.Controls.Add(datetimeLabel);
            this.Controls.Add(this.datetimeDateTimePicker);
            this.Controls.Add(this.comissionBindingNavigator);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormEditComission";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Журнал сдачи на комиссию";
            this.Load += new System.EventHandler(this.FormEditComission_Load);
            ((System.ComponentModel.ISupportInitialize)(this.storeDBDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.comissionBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.comissionBindingNavigator)).EndInit();
            this.comissionBindingNavigator.ResumeLayout(false);
            this.comissionBindingNavigator.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.clientsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.productsBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private StoreDBDataSet storeDBDataSet;
        private System.Windows.Forms.BindingSource comissionBindingSource;
        private StoreDBDataSetTableAdapters.ComissionTableAdapter comissionTableAdapter;
        private StoreDBDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingNavigator comissionBindingNavigator;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
        private System.Windows.Forms.ToolStripButton comissionBindingNavigatorSaveItem;
        private System.Windows.Forms.Label idLabel1;
        private System.Windows.Forms.ComboBox clientIdComboBox;
        private System.Windows.Forms.ComboBox productIdComboBox;
        private System.Windows.Forms.DateTimePicker datetimeDateTimePicker;
        private System.Windows.Forms.BindingSource clientsBindingSource;
        private StoreDBDataSetTableAdapters.ClientsTableAdapter clientsTableAdapter;
        private System.Windows.Forms.BindingSource productsBindingSource;
        private StoreDBDataSetTableAdapters.ProductsTableAdapter productsTableAdapter;
    }
}