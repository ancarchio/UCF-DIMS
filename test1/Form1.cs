using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Runtime.Serialization;

namespace test1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            comboSerialPorts.Items.AddRange(ports);
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = comboSerialPorts.Text;
                serialPort1.Open();

                timerReadSerial.Start();

                terminal.AppendText("Serial Connected\n");
                
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message, "error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            
        }

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            serialPort1.Close();

            timerReadSerial.Stop();

            terminal.AppendText("Serial Ended");
        }

        private void groupBox1_Enter_1(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void comboSerialPorts_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void timerReadSerial_Tick(object sender, EventArgs e)
        {
              string serial = serialPort1.ReadExisting();
            string[] line = serial.Split('\n');
            foreach (string s in line)
            {
                try
                {
                    string value = s.Substring(3);
                    string index = s.Substring(0, 3);
                    if (index == "Er.") //errors
                    {
                        if (value == "11")
                        {
                            MessageBox.Show("Error 11: Invalid Temperature");
                            errorProvider1.SetError(textBoxNTemp, "Invalid, set 1-250");
                        }
                        if (value == "12")
                        {
                            MessageBox.Show("Error 12: Invalid Heat Time");
                            errorProvider1.SetError(textBoxHeatTime, "Invalid, set > 0");
                        }
                        if (value == "13")
                        {
                            MessageBox.Show("Error 13: Invalid Hold Time");
                            errorProvider1.SetError(textBoxWaitTime, "Invalid, set > 0");
                        }
                        if (value == "14")
                        {
                            MessageBox.Show("Error 14: Invalid Cool Time");
                            errorProvider1.SetError(textBoxCoolTime, "Invalid, set > 0");
                        }
                        if (value == "31")
                        {
                            MessageBox.Show("Error 31: Barrel Overheating \nWait for machine to cool");
                        }
                        if (value == "32")
                        {
                            MessageBox.Show("Error 32: Electronics Overheating \nWait for machine to cool");
                        }
                        if (value == "33")
                        {
                            MessageBox.Show("Error 33: Mold Cavity Overheating \nWait for machine to cool");
                        }
                        if (value == "41")
                        {
                            MessageBox.Show("Error 41: Gate 1 Open \nPlease close door and reset machine");
                        }
                        if (value == "42")
                        {
                            MessageBox.Show("Error 42: Gate 2 Open \nPlease close door and reset machine");
                        }
                    }
                    if (index == "T1.") //Barrel Temp 1
                    {
                        printBT1.Clear();
                        printBT1.AppendText(value);
                    }
                    if (index == "T2.") //Barrel Temp 2
                    {
                        printBT2.Clear();
                        printBT2.AppendText(value);
                    }
                    if (index == "T3.") //Electronics Temp
                    {
                        printET.Clear();
                        printET.AppendText(value);
                    }
                    if (index == "T4.") //Mold Temp
                    {
                        printMT.Clear();
                        printMT.AppendText(value);
                    }
                    if (index == "G1.") //Gate 1
                    {
                        printG1.Clear();
                        if (value == "1\r")
                        {
                            printG1.AppendText("Open");
                        }
                        else if (value == "0\r")
                        {
                            printG1.AppendText("Closed");
                        }
                    }
                    if (index == "G2.") //Gate 2
                    {
                        printG2.Clear();
                        if (value == "1\r")
                        {
                            printG2.AppendText("Open");
                        }
                        else if (value == "0\r")
                        {
                            printG2.AppendText("Closed");
                        }
                    }
                    if (index == "SL.") //Solenoid L1
                    {
                        printSL.Clear();
                        if (value == "1\r")
                        {
                            printSL.AppendText("Open");
                        }
                        else if (value == "0\r")
                        {
                            printSL.AppendText("Closed");
                        }
                    }
                    if (index == "SR.") //Solenoid R1
                    {
                        printSR.Clear();
                        if (value == "1\r")
                        {
                            printSR.AppendText("Open");
                        }
                        else if (value == "0\r")
                        {
                            printSR.AppendText("Closed");
                        }
                    }
                    if (index == "IP.")
                    {
                        terminal.Clear();
                        if (value == "1\r")
                        {
                            terminal.AppendText("Heating Material");
                        }
                        if (value == "2\r")
                        {
                            terminal.AppendText("Injecting then holding");
                        }
                        if (value == "3\r")
                        {
                            terminal.AppendText("Cooling");
                        }
                        if (value == "4\r")
                        {
                            terminal.AppendText("Process Complete!\n Carefully remove the mold");
                            progressBar.Value = 0;
                        }
                    }
                    if (index == "PT.")
                    {
                        progressBar.Value = (int)double.Parse(value.Trim());
                    }
                    if (index == "HH.")
                    {
                        printHeaters.Clear();
                        if (value == "1\r")
                        {
                            printHeaters.AppendText("On");
                        }
                        if (value == "0\r")
                        {
                            printHeaters.AppendText("Off");
                        }
                    }
                }
                catch
                {
                    Console.WriteLine("End of Processing.");
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
            serialPort1.Write("NT.");
            serialPort1.WriteLine(textBoxNTemp.Text);
            Console.Write("NT.");
            Console.WriteLine(textBoxNTemp.Text);
            }
            else
            {
                MessageBox.Show("Error 20: Serial Port Not Connected");
            }
        }
        private void textBoxHeatTime_TextChanged(object sender, EventArgs e)
        {
           if (serialPort1.IsOpen)
            {
                serialPort1.Write("HT.");
                serialPort1.WriteLine(textBoxHeatTime.Text);
                Console.Write("HT.");
                Console.WriteLine(textBoxHeatTime.Text);
            }
           else
            {
                MessageBox.Show("Error 20: Serial Port Not Connected");
            }
            
        }
        private void textBoxHoldTime_TextChanged(object sender, EventArgs e)
        {
            
            if (serialPort1.IsOpen)
            {
            serialPort1.Write("WT.");
            serialPort1.WriteLine(textBoxWaitTime.Text);
            Console.Write("WT.");
            Console.WriteLine(textBoxWaitTime.Text);
            }
            else
            {
                MessageBox.Show("Error 20: Serial Port Not Connected");
            }
        }
        private void textBoxCoolTime_TextChanged(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
            serialPort1.Write("CT.");
            serialPort1.WriteLine(textBoxCoolTime.Text);
            Console.Write("CT.");
            Console.WriteLine(textBoxCoolTime.Text);
            }
            else
            {
                MessageBox.Show("Error 20: Serial Port Not Connected");
            }
        }
        private void label16_Click(object sender, EventArgs e)
        {

        }
        private void toolTip1_Popup(object sender, PopupEventArgs e)
        {

        }
        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }
        private void buttonStart_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("PS.1");
            Console.WriteLine("PS.1");
        }
        private void progressBar_Click(object sender, EventArgs e)
        {

        }
        private void label13_Click(object sender, EventArgs e)
        {

        }
        private void fanOn_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("F1.1");
        }
        private void fanOff_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("F1.0");
        }
        private void solOn_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("S1.1");
        }
        private void solOff_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("S1.0");
        }
        private void heaterOn_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("H1.1");
        }
        private void heaterOff_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("H1.0");
        }
    }
}
