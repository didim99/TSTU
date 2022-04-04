namespace OOP_lab11
{
    partial class FormEditPurchase
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
            System.Windows.Forms.Label datetimeLabel;
            System.Windows.Forms.Label productIdLabel;
            System.Windows.Forms.Label operationIdLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormEditPurchase));
            this.storeDBDataSet = new OOP_lab11.StoreDBDataSet();
            this.logPurchaseBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.logPurchaseTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.LogPurchaseTableAdapter();
            this.tableAdapterManager = new OOP_lab11.StoreDBDataSetTableAdapters.TableAdapterManager();
            this.productsTableAdapter = new OOP_lab11.StoreDBDataSetTableAdapters.ProductsTableAdapter();
            this.logPurchaseBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
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
            this.logPurchaseBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.idLabel1 = new System.Windows.Forms.Label();
            this.datetimeDateTimePicker = new System.Windows.Forms.DateTimePicker();
            this.productIdComboBox = new System.Windows.Forms.ComboBox();
            this.productsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.operationIdMaskedTextBox = new System.Windows.Forms.MaskedTextBox();
            idLabel = new System.Windows.Forms.Label();
            datetimeLabel = new System.Windows.Forms.Label();
            productIdLabel = new System.Windows.Forms.Label();
            operationIdLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.storeDBDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseBindingNavigator)).BeginInit();
            this.logPurchaseBindingNavigator.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.productsBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // idLabel
            // 
            idLabel.AutoSize = true;
            idLabel.Location = new System.Drawing.Point(85, 40);
            idLabel.Name = "idLabel";
            idLabel.Size = new System.Drawing.Size(26, 17);
            idLabel.TabIndex = 1;
            idLabel.Text = "№:";
            // 
            // datetimeLabel
            // 
            datetimeLabel.AutoSize = true;
            datetimeLabel.Location = new System.Drawing.Point(65, 66);
            datetimeLabel.Name = "datetimeLabel";
            datetimeLabel.Size = new System.Drawing.Size(46, 17);
            datetimeLabel.TabIndex = 3;
            datetimeLabel.Text = "Дата:";
            // 
            // productIdLabel
            // 
            productIdLabel.AutoSize = true;
            productIdLabel.Location = new System.Drawing.Point(42, 97);
            productIdLabel.Name = "productIdLabel";
            productIdLabel.Size = new System.Drawing.Size(69, 17);
            productIdLabel.TabIndex = 5;
            productIdLabel.Text = "Изделие:";
            // 
            // operationIdLabel
            // 
            operationIdLabel.AutoSize = true;
            operationIdLabel.Location = new System.Drawing.Point(6, 128);
            operationIdLabel.Name = "operationIdLabel";
            operationIdLabel.Size = new System.Drawing.Size(105, 17);
            operationIdLabel.TabIndex = 7;
            operationIdLabel.Text = "Код операции:";
            // 
            // storeDBDataSet
            // 
            this.storeDBDataSet.DataSetName = "StoreDBDataSet";
            this.storeDBDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // logPurchaseBindingSource
            // 
            this.logPurchaseBindingSource.DataMember = "LogPurchase";
            this.logPurchaseBindingSource.DataSource = this.storeDBDataSet;
            // 
            // logPurchaseTableAdapter
            // 
            this.logPurchaseTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.ClientsTableAdapter = null;
            this.tableAdapterManager.ComissionTableAdapter = null;
            this.tableAdapterManager.LogPurchaseTableAdapter = this.logPurchaseTableAdapter;
            this.tableAdapterManager.LogSaleTableAdapter = null;
            this.tableAdapterManager.ProductsTableAdapter = this.productsTableAdapter;
            this.tableAdapterManager.UpdateOrder = OOP_lab11.StoreDBDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // productsTableAdapter
            // 
            this.productsTableAdapter.ClearBeforeFill = true;
            // 
            // logPurchaseBindingNavigator
            // 
            this.logPurchaseBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
            this.logPurchaseBindingNavigator.BindingSource = this.logPurchaseBindingSource;
            this.logPurchaseBindingNavigator.CountItem = this.bindingNavigatorCountItem;
            this.logPurchaseBindingNavigator.CountItemFormat = "из {0}";
            this.logPurchaseBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
            this.logPurchaseBindingNavigator.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.logPurchaseBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
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
            this.logPurchaseBindingNavigatorSaveItem});
            this.logPurchaseBindingNavigator.Location = new System.Drawing.Point(0, 0);
            this.logPurchaseBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.logPurchaseBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.logPurchaseBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.logPurchaseBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.logPurchaseBindingNavigator.Name = "logPurchaseBindingNavigator";
            this.logPurchaseBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
            this.logPurchaseBindingNavigator.Size = new System.Drawing.Size(326, 27);
            this.logPurchaseBindingNavigator.TabIndex = 0;
            this.logPurchaseBindingNavigator.Text = "bindingNavigator1";
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
            // logPurchaseBindingNavigatorSaveItem
            // 
            this.logPurchaseBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.logPurchaseBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("logPurchaseBindingNavigatorSaveItem.Image")));
            this.logPurchaseBindingNavigatorSaveItem.Name = "logPurchaseBindingNavigatorSaveItem";
            this.logPurchaseBindingNavigatorSaveItem.Size = new System.Drawing.Size(24, 24);
            this.logPurchaseBindingNavigatorSaveItem.Text = "Сохранить данные";
            this.logPurchaseBindingNavigatorSaveItem.Click += new System.EventHandler(this.logPurchaseBindingNavigatorSaveItem_Click);
            // 
            // idLabel1
            // 
            this.idLabel1.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.logPurchaseBindingSource, "Id", true));
            this.idLabel1.Location = new System.Drawing.Point(117, 40);
            this.idLabel1.Name = "idLabel1";
            this.idLabel1.Size = new System.Drawing.Size(200, 23);
            this.idLabel1.TabIndex = 2;
            this.idLabel1.Text = "label1";
            // 
            // datetimeDateTimePicker
            // 
            this.datetimeDateTimePicker.CustomFormat = "dd.MM.yyyy HH:mm";
            this.datetimeDateTimePicker.DataBindings.Add(new System.Windows.Forms.Binding("Value", this.logPurchaseBindingSource, "Datetime", true));
            this.datetimeDateTimePicker.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.datetimeDateTimePicker.Location = new System.Drawing.Point(117, 66);
            this.datetimeDateTimePicker.Name = "datetimeDateTimePicker";
            this.datetimeDateTimePicker.Size = new System.Drawing.Size(200, 22);
            this.datetimeDateTimePicker.TabIndex = 4;
            // 
            // productIdComboBox
            // 
            this.productIdComboBox.DataBindings.Add(new System.Windows.Forms.Binding("SelectedValue", this.logPurchaseBindingSource, "ProductId", true));
            this.productIdComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.productsBindingSource, "Name", true));
            this.productIdComboBox.DataSource = this.productsBindingSource;
            this.productIdComboBox.DisplayMember = "Name";
            this.productIdComboBox.FormattingEnabled = true;
            this.productIdComboBox.Location = new System.Drawing.Point(117, 94);
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
            // operationIdMaskedTextBox
            // 
            this.operationIdMaskedTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.logPurchaseBindingSource, "OperationId", true));
            this.operationIdMaskedTextBox.Location = new System.Drawing.Point(120, 125);
            this.operationIdMaskedTextBox.Mask = "000-000";
            this.operationIdMaskedTextBox.Name = "operationIdMaskedTextBox";
            this.operationIdMaskedTextBox.Size = new System.Drawing.Size(197, 22);
            this.operationIdMaskedTextBox.TabIndex = 9;
            // 
            // FormEditPurchase
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(326, 156);
            this.Controls.Add(this.operationIdMaskedTextBox);
            this.Controls.Add(idLabel);
            this.Controls.Add(this.idLabel1);
            this.Controls.Add(datetimeLabel);
            this.Controls.Add(this.datetimeDateTimePicker);
            this.Controls.Add(productIdLabel);
            this.Controls.Add(this.productIdComboBox);
            this.Controls.Add(operationIdLabel);
            this.Controls.Add(this.logPurchaseBindingNavigator);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormEditPurchase";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Журнал покупки";
            this.Load += new System.EventHandler(this.FormEditPurchase_Load);
            ((System.ComponentModel.ISupportInitialize)(this.storeDBDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.logPurchaseBindingNavigator)).EndInit();
            this.logPurchaseBindingNavigator.ResumeLayout(false);
            this.logPurchaseBindingNavigator.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.productsBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private StoreDBDataSet storeDBDataSet;
        private System.Windows.Forms.BindingSource logPurchaseBindingSource;
        private StoreDBDataSetTableAdapters.LogPurchaseTableAdapter logPurchaseTableAdapter;
        private StoreDBDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingNavigator logPurchaseBindingNavigator;
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
        private System.Windows.Forms.ToolStripButton logPurchaseBindingNavigatorSaveItem;
        private StoreDBDataSetTableAdapters.ProductsTableAdapter productsTableAdapter;
        private System.Windows.Forms.Label idLabel1;
        private System.Windows.Forms.DateTimePicker datetimeDateTimePicker;
        private System.Windows.Forms.ComboBox productIdComboBox;
        private System.Windows.Forms.BindingSource productsBindingSource;
        private System.Windows.Forms.MaskedTextBox operationIdMaskedTextBox;
    }
}