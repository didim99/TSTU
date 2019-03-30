using System;
using System.Globalization;

namespace MP_L4_T5
{
    public class Meeting
    {
        private CultureInfo ci;
        private string format = @"HH\:mm";
        private DateTime Start, End;
        private int grade = 5;

        public string Company { get; set; }
        public string Address { get; set; }

        public int Grade
        {
            get
            {
                return grade;
            }
            set
            {
                if (value < 1 || value > 5)
                    throw new ArgumentException("Invalid grade");
                grade = value;
            }
        }

        public Meeting()
        {
            ci = new CultureInfo("ru-RU");
            Start = new DateTime();
            End = new DateTime();
        }

        public string TStart
        {
            set
            {
                Start = DateTime.ParseExact(value, format, ci);
            }
            get
            {
                return Start.ToString(format, ci);
            }
        }

        public string TEnd
        {
            set
            {
                End = DateTime.ParseExact(value, format, ci);
                if (End <= Start) throw new ArgumentException("Invalid interval");
            }
            get
            {
                return End.ToString(format, ci);
            }
        }

        public string TLength
        {
            get
            {
                return (End - Start).ToString(@"hh\:mm", ci);
            }
        }
    }
}
