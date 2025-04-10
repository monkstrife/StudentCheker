using Microsoft.Win32;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System;
using System.IO;
using System.Windows;
using Microsoft.Win32;
using System.Diagnostics;

namespace StudentCheker
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        string currentLab;
        string currentV;
        string[] currentfilenames = new string[0];

        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnOpenFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "CPP files (*.cpp;*.h)|*.cpp;*.h";
            openFileDialog.Multiselect = true;
            TB.Text = "";

            if (openFileDialog.ShowDialog() == true)
            {
                currentfilenames = new string[openFileDialog.FileNames.Length];

                int i = 0;
                foreach (string filename in openFileDialog.FileNames)
                {
                    TB.Text += System.IO.Path.GetFileName(filename) + " ";
                    currentfilenames[i++] = filename;
                }
            }
        }

        private void RadioButton1_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton pressed = (RadioButton)sender;
            currentLab = pressed.Content.ToString();
        }

        private void RadioButton2_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton pressed = (RadioButton)sender;
            currentV = pressed.Content.ToString();
        }

        private void startCheck(object sender, RoutedEventArgs e)
        {
            if(currentLab == "5")
            {
                Process.Start("../../../../project/lab5_plug/delete.bat").WaitForExit();
            }
            if(currentfilenames.Length > 0)
            {
                for(int i = 0; i < currentfilenames.Length; i++)
                {
                    string path = @currentfilenames[i];
                    string newPath = "C:\\Users\\drobi\\source\\repos\\StudentCheker\\project\\Lab"+ currentLab + "_plug\\Lab"+ currentLab + "_plug\\" + System.IO.Path.GetFileName(currentfilenames[i]);
                    FileInfo fileInf = new FileInfo(path);
                    if (fileInf.Exists)
                    {
                        fileInf.CopyTo(newPath, true);
                        // альтернатива с помощью класса File
                        // File.Move(path, newPath, true);
                    }
                }
            }
            Process.Start("../../../../project/lab"+ currentLab + "_plug/refresh.bat").WaitForExit();
            Process.Start("../../../../project/lab"+ currentLab + "_plug/x64/Debug/V" + currentV + ".bat");
        }
    }
}