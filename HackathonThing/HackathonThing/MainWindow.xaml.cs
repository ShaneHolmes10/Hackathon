using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;

namespace HackathonThing
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        SerialPort sp = new SerialPort();

        public MainWindow()
        {
            InitializeComponent();

            sp.BaudRate = 9600;
            sp.PortName = "COM4";

            sp.Open();

            


        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            
            
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            sp.Write(new byte[] { 0x01 }, 0, 1);
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            sp.Write(new byte[] { 0x02 }, 0, 1);
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            sp.Write(new byte[] { 0x03 }, 0, 1);
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            sp.Write(new byte[] { ((byte)((255 - 180) + (int)((Slider)sender).Value)) }, 0, 1);

        }
    }

    

}
