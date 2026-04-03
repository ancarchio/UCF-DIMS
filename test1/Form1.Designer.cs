namespace test1
{
    partial class Form1
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
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.serialBox = new System.Windows.Forms.GroupBox();
            this.buttonConnect = new System.Windows.Forms.Button();
            this.buttonDisconnect = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.comboSerialPorts = new System.Windows.Forms.ComboBox();
            this.groupCurrData = new System.Windows.Forms.GroupBox();
            this.label13 = new System.Windows.Forms.Label();
            this.printHeaters = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.printSR = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.printSL = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.printMT = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.printBT2 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.printET = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.printG1 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.printG2 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.printBT1 = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.timerReadSerial = new System.Windows.Forms.Timer(this.components);
            this.terminal = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.textBoxNTemp = new System.Windows.Forms.TextBox();
            this.textBoxHeatTime = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.textBoxCoolTime = new System.Windows.Forms.TextBox();
            this.label16 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.textBoxWaitTime = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.buttonStart = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.fanOn = new System.Windows.Forms.Button();
            this.fanOff = new System.Windows.Forms.Button();
            this.solOff = new System.Windows.Forms.Button();
            this.solOn = new System.Windows.Forms.Button();
            this.heaterOff = new System.Windows.Forms.Button();
            this.heaterOn = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
            this.serialBox.SuspendLayout();
            this.groupCurrData.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.PortName = "COM6";
            // 
            // serialBox
            // 
            this.serialBox.Controls.Add(this.buttonConnect);
            this.serialBox.Controls.Add(this.buttonDisconnect);
            this.serialBox.Controls.Add(this.label1);
            this.serialBox.Controls.Add(this.comboSerialPorts);
            this.serialBox.Location = new System.Drawing.Point(31, 32);
            this.serialBox.Name = "serialBox";
            this.serialBox.Size = new System.Drawing.Size(204, 107);
            this.serialBox.TabIndex = 2;
            this.serialBox.TabStop = false;
            this.serialBox.Text = "Serial Connection";
            this.serialBox.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // buttonConnect
            // 
            this.buttonConnect.Location = new System.Drawing.Point(6, 63);
            this.buttonConnect.Name = "buttonConnect";
            this.buttonConnect.Size = new System.Drawing.Size(94, 29);
            this.buttonConnect.TabIndex = 4;
            this.buttonConnect.Text = "Connect";
            this.buttonConnect.UseVisualStyleBackColor = true;
            this.buttonConnect.Click += new System.EventHandler(this.buttonConnect_Click);
            // 
            // buttonDisconnect
            // 
            this.buttonDisconnect.Location = new System.Drawing.Point(106, 63);
            this.buttonDisconnect.Name = "buttonDisconnect";
            this.buttonDisconnect.Size = new System.Drawing.Size(92, 29);
            this.buttonDisconnect.TabIndex = 3;
            this.buttonDisconnect.Text = "Disconnect";
            this.buttonDisconnect.UseVisualStyleBackColor = true;
            this.buttonDisconnect.Click += new System.EventHandler(this.buttonDisconnect_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "COM Port";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // comboSerialPorts
            // 
            this.comboSerialPorts.FormattingEnabled = true;
            this.comboSerialPorts.Location = new System.Drawing.Point(85, 32);
            this.comboSerialPorts.Name = "comboSerialPorts";
            this.comboSerialPorts.Size = new System.Drawing.Size(113, 24);
            this.comboSerialPorts.TabIndex = 0;
            this.comboSerialPorts.SelectedIndexChanged += new System.EventHandler(this.comboSerialPorts_SelectedIndexChanged);
            // 
            // groupCurrData
            // 
            this.groupCurrData.Controls.Add(this.label13);
            this.groupCurrData.Controls.Add(this.printHeaters);
            this.groupCurrData.Controls.Add(this.label11);
            this.groupCurrData.Controls.Add(this.label10);
            this.groupCurrData.Controls.Add(this.printSR);
            this.groupCurrData.Controls.Add(this.label9);
            this.groupCurrData.Controls.Add(this.label8);
            this.groupCurrData.Controls.Add(this.printSL);
            this.groupCurrData.Controls.Add(this.label7);
            this.groupCurrData.Controls.Add(this.printMT);
            this.groupCurrData.Controls.Add(this.label6);
            this.groupCurrData.Controls.Add(this.printBT2);
            this.groupCurrData.Controls.Add(this.label5);
            this.groupCurrData.Controls.Add(this.printET);
            this.groupCurrData.Controls.Add(this.label4);
            this.groupCurrData.Controls.Add(this.printG1);
            this.groupCurrData.Controls.Add(this.label3);
            this.groupCurrData.Controls.Add(this.printG2);
            this.groupCurrData.Controls.Add(this.label2);
            this.groupCurrData.Controls.Add(this.printBT1);
            this.groupCurrData.Location = new System.Drawing.Point(31, 155);
            this.groupCurrData.Name = "groupCurrData";
            this.groupCurrData.Size = new System.Drawing.Size(203, 311);
            this.groupCurrData.TabIndex = 3;
            this.groupCurrData.TabStop = false;
            this.groupCurrData.Text = "Current Data";
            this.groupCurrData.Enter += new System.EventHandler(this.groupBox1_Enter_1);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(6, 267);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(55, 16);
            this.label13.TabIndex = 21;
            this.label13.Text = "Heaters";
            this.label13.Click += new System.EventHandler(this.label13_Click);
            // 
            // printHeaters
            // 
            this.printHeaters.Location = new System.Drawing.Point(99, 264);
            this.printHeaters.Name = "printHeaters";
            this.printHeaters.ReadOnly = true;
            this.printHeaters.Size = new System.Drawing.Size(91, 22);
            this.printHeaters.TabIndex = 20;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(8, 295);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(0, 16);
            this.label11.TabIndex = 19;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(6, 239);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(74, 16);
            this.label10.TabIndex = 17;
            this.label10.Text = "Solenoid R";
            // 
            // printSR
            // 
            this.printSR.Location = new System.Drawing.Point(99, 236);
            this.printSR.Name = "printSR";
            this.printSR.ReadOnly = true;
            this.printSR.Size = new System.Drawing.Size(91, 22);
            this.printSR.TabIndex = 16;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(8, 239);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(0, 16);
            this.label9.TabIndex = 15;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(8, 211);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(71, 16);
            this.label8.TabIndex = 13;
            this.label8.Text = "Solenoid L";
            this.label8.Click += new System.EventHandler(this.label8_Click);
            // 
            // printSL
            // 
            this.printSL.Location = new System.Drawing.Point(99, 207);
            this.printSL.Name = "printSL";
            this.printSL.ReadOnly = true;
            this.printSL.Size = new System.Drawing.Size(91, 22);
            this.printSL.TabIndex = 12;
            this.printSL.TextChanged += new System.EventHandler(this.textBox8_TextChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(8, 126);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(79, 16);
            this.label7.TabIndex = 11;
            this.label7.Text = "Mold Temp.";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // printMT
            // 
            this.printMT.Location = new System.Drawing.Point(129, 122);
            this.printMT.Name = "printMT";
            this.printMT.ReadOnly = true;
            this.printMT.Size = new System.Drawing.Size(61, 22);
            this.printMT.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(8, 67);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(95, 16);
            this.label6.TabIndex = 9;
            this.label6.Text = "Barrel Temp. 2";
            // 
            // printBT2
            // 
            this.printBT2.Location = new System.Drawing.Point(129, 63);
            this.printBT2.Name = "printBT2";
            this.printBT2.ReadOnly = true;
            this.printBT2.Size = new System.Drawing.Size(61, 22);
            this.printBT2.TabIndex = 8;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(8, 96);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(115, 16);
            this.label5.TabIndex = 7;
            this.label5.Text = "Electronics Temp.";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // printET
            // 
            this.printET.Location = new System.Drawing.Point(129, 92);
            this.printET.Name = "printET";
            this.printET.ReadOnly = true;
            this.printET.Size = new System.Drawing.Size(61, 22);
            this.printET.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 155);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(46, 16);
            this.label4.TabIndex = 5;
            this.label4.Text = "Gate 1";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // printG1
            // 
            this.printG1.Location = new System.Drawing.Point(99, 151);
            this.printG1.Name = "printG1";
            this.printG1.ReadOnly = true;
            this.printG1.Size = new System.Drawing.Size(91, 22);
            this.printG1.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 183);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 16);
            this.label3.TabIndex = 3;
            this.label3.Text = "Gate 2";
            // 
            // printG2
            // 
            this.printG2.Location = new System.Drawing.Point(99, 179);
            this.printG2.Name = "printG2";
            this.printG2.ReadOnly = true;
            this.printG2.Size = new System.Drawing.Size(91, 22);
            this.printG2.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(95, 16);
            this.label2.TabIndex = 1;
            this.label2.Text = "Barrel Temp. 1";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // printBT1
            // 
            this.printBT1.Location = new System.Drawing.Point(129, 34);
            this.printBT1.Name = "printBT1";
            this.printBT1.ReadOnly = true;
            this.printBT1.Size = new System.Drawing.Size(61, 22);
            this.printBT1.TabIndex = 0;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(20, 40);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(110, 16);
            this.label12.TabIndex = 0;
            this.label12.Text = "Nozzle Temp. (C)";
            this.toolTip1.SetToolTip(this.label12, "Find nozzle temperature from material data sheet");
            this.label12.Click += new System.EventHandler(this.label12_Click);
            // 
            // timerReadSerial
            // 
            this.timerReadSerial.Interval = 1000;
            this.timerReadSerial.Tick += new System.EventHandler(this.timerReadSerial_Tick);
            // 
            // terminal
            // 
            this.terminal.BackColor = System.Drawing.Color.White;
            this.terminal.Location = new System.Drawing.Point(25, 27);
            this.terminal.Multiline = true;
            this.terminal.Name = "terminal";
            this.terminal.ReadOnly = true;
            this.terminal.Size = new System.Drawing.Size(232, 113);
            this.terminal.TabIndex = 5;
            this.terminal.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.progressBar);
            this.groupBox1.Controls.Add(this.terminal);
            this.groupBox1.Location = new System.Drawing.Point(297, 281);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(283, 185);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Process";
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(25, 146);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(230, 23);
            this.progressBar.TabIndex = 6;
            this.progressBar.Click += new System.EventHandler(this.progressBar_Click);
            // 
            // textBoxNTemp
            // 
            this.textBoxNTemp.Location = new System.Drawing.Point(147, 34);
            this.textBoxNTemp.Name = "textBoxNTemp";
            this.textBoxNTemp.Size = new System.Drawing.Size(100, 22);
            this.textBoxNTemp.TabIndex = 1;
            this.toolTip1.SetToolTip(this.textBoxNTemp, "Find nozzle temperature from material data sheet");
            this.textBoxNTemp.TextChanged += new System.EventHandler(this.textBox1_TextChanged_1);
            // 
            // textBoxHeatTime
            // 
            this.textBoxHeatTime.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.textBoxHeatTime.Location = new System.Drawing.Point(147, 72);
            this.textBoxHeatTime.Name = "textBoxHeatTime";
            this.textBoxHeatTime.Size = new System.Drawing.Size(100, 22);
            this.textBoxHeatTime.TabIndex = 7;
            this.toolTip1.SetToolTip(this.textBoxHeatTime, "Calculated using Nozzle Temperatiure and Shot Size");
            this.textBoxHeatTime.TextChanged += new System.EventHandler(this.textBoxHeatTime_TextChanged);
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(20, 75);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(88, 16);
            this.label15.TabIndex = 6;
            this.label15.Text = "Heat Time (s)";
            this.toolTip1.SetToolTip(this.label15, "Calculated using Nozzle Temperatiure and Shot Size");
            // 
            // textBoxCoolTime
            // 
            this.textBoxCoolTime.Location = new System.Drawing.Point(147, 143);
            this.textBoxCoolTime.Name = "textBoxCoolTime";
            this.textBoxCoolTime.Size = new System.Drawing.Size(100, 22);
            this.textBoxCoolTime.TabIndex = 12;
            this.textBoxCoolTime.TextChanged += new System.EventHandler(this.textBoxCoolTime_TextChanged);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(20, 112);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(88, 16);
            this.label16.TabIndex = 9;
            this.label16.Text = "Hold Time (s)";
            this.label16.Click += new System.EventHandler(this.label16_Click);
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(20, 149);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(87, 16);
            this.label17.TabIndex = 11;
            this.label17.Text = "Cool Time (s)";
            // 
            // textBoxWaitTime
            // 
            this.textBoxWaitTime.Location = new System.Drawing.Point(147, 106);
            this.textBoxWaitTime.Name = "textBoxWaitTime";
            this.textBoxWaitTime.Size = new System.Drawing.Size(100, 22);
            this.textBoxWaitTime.TabIndex = 10;
            this.textBoxWaitTime.TextChanged += new System.EventHandler(this.textBoxHoldTime_TextChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.buttonStart);
            this.groupBox2.Controls.Add(this.label12);
            this.groupBox2.Controls.Add(this.textBoxCoolTime);
            this.groupBox2.Controls.Add(this.label16);
            this.groupBox2.Controls.Add(this.textBoxNTemp);
            this.groupBox2.Controls.Add(this.label17);
            this.groupBox2.Controls.Add(this.label15);
            this.groupBox2.Controls.Add(this.textBoxHeatTime);
            this.groupBox2.Controls.Add(this.textBoxWaitTime);
            this.groupBox2.Location = new System.Drawing.Point(297, 32);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(283, 235);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Setup";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(86, 185);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(110, 30);
            this.buttonStart.TabIndex = 13;
            this.buttonStart.Text = "Begin Injection";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // toolTip1
            // 
            this.toolTip1.Popup += new System.Windows.Forms.PopupEventHandler(this.toolTip1_Popup);
            // 
            // fanOn
            // 
            this.fanOn.Location = new System.Drawing.Point(36, 32);
            this.fanOn.Name = "fanOn";
            this.fanOn.Size = new System.Drawing.Size(102, 29);
            this.fanOn.TabIndex = 14;
            this.fanOn.Text = "Fan On";
            this.fanOn.UseVisualStyleBackColor = true;
            this.fanOn.Click += new System.EventHandler(this.fanOn_Click);
            // 
            // fanOff
            // 
            this.fanOff.Location = new System.Drawing.Point(144, 32);
            this.fanOff.Name = "fanOff";
            this.fanOff.Size = new System.Drawing.Size(102, 29);
            this.fanOff.TabIndex = 15;
            this.fanOff.Text = "Fan Off";
            this.fanOff.UseVisualStyleBackColor = true;
            this.fanOff.Click += new System.EventHandler(this.fanOff_Click);
            // 
            // solOff
            // 
            this.solOff.Location = new System.Drawing.Point(144, 67);
            this.solOff.Name = "solOff";
            this.solOff.Size = new System.Drawing.Size(102, 29);
            this.solOff.TabIndex = 17;
            this.solOff.Text = "Solenoid Off";
            this.solOff.UseVisualStyleBackColor = true;
            this.solOff.Click += new System.EventHandler(this.solOff_Click);
            // 
            // solOn
            // 
            this.solOn.Location = new System.Drawing.Point(36, 67);
            this.solOn.Name = "solOn";
            this.solOn.Size = new System.Drawing.Size(102, 29);
            this.solOn.TabIndex = 16;
            this.solOn.Text = "Solenoid On";
            this.solOn.UseVisualStyleBackColor = true;
            this.solOn.Click += new System.EventHandler(this.solOn_Click);
            // 
            // heaterOff
            // 
            this.heaterOff.Location = new System.Drawing.Point(144, 102);
            this.heaterOff.Name = "heaterOff";
            this.heaterOff.Size = new System.Drawing.Size(102, 28);
            this.heaterOff.TabIndex = 19;
            this.heaterOff.Text = "Heater Off";
            this.heaterOff.UseVisualStyleBackColor = true;
            this.heaterOff.Click += new System.EventHandler(this.heaterOff_Click);
            // 
            // heaterOn
            // 
            this.heaterOn.Location = new System.Drawing.Point(36, 102);
            this.heaterOn.Name = "heaterOn";
            this.heaterOn.Size = new System.Drawing.Size(102, 28);
            this.heaterOn.TabIndex = 18;
            this.heaterOn.Text = "Heater On";
            this.heaterOn.UseVisualStyleBackColor = true;
            this.heaterOn.Click += new System.EventHandler(this.heaterOn_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.fanOn);
            this.groupBox3.Controls.Add(this.heaterOff);
            this.groupBox3.Controls.Add(this.fanOff);
            this.groupBox3.Controls.Add(this.heaterOn);
            this.groupBox3.Controls.Add(this.solOn);
            this.groupBox3.Controls.Add(this.solOff);
            this.groupBox3.Location = new System.Drawing.Point(645, 32);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(283, 155);
            this.groupBox3.TabIndex = 14;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Testing";
            // 
            // errorProvider1
            // 
            this.errorProvider1.ContainerControl = this;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(948, 565);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupCurrData);
            this.Controls.Add(this.serialBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.serialBox.ResumeLayout(false);
            this.serialBox.PerformLayout();
            this.groupCurrData.ResumeLayout(false);
            this.groupCurrData.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.GroupBox serialBox;
        private System.Windows.Forms.ComboBox comboSerialPorts;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonDisconnect;
        private System.Windows.Forms.Button buttonConnect;
        private System.Windows.Forms.GroupBox groupCurrData;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox printBT1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox printET;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox printG1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox printG2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox printMT;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox printBT2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox printSL;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox printSR;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Timer timerReadSerial;
        private System.Windows.Forms.TextBox terminal;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBoxNTemp;
        private System.Windows.Forms.TextBox textBoxHeatTime;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox textBoxCoolTime;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.TextBox textBoxWaitTime;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox printHeaters;
        private System.Windows.Forms.Button fanOn;
        private System.Windows.Forms.Button fanOff;
        private System.Windows.Forms.Button solOff;
        private System.Windows.Forms.Button solOn;
        private System.Windows.Forms.Button heaterOff;
        private System.Windows.Forms.Button heaterOn;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.ErrorProvider errorProvider1;
    }
}

