using System;
using System.Collections.Generic;
using System.Text;

namespace String
{
    class String
    {
        readonly private byte[] content;
        private int[] nextArry=null;
        private const byte SPACE = 32;
        public const int NOPS = -1;
        public int Length => content.Length;
        public String(string s)
        {
            content = Encoding.ASCII.GetBytes(s);
        }

        private String(byte[] bytes)
        {
            content = bytes;
        }

        static public bool operator >(String lop, String rop)
        {
            for (int i = 0; i < lop.Length && i < rop.Length; ++i)
            {
                if (lop.content[i] != rop.content[i])
                {
                    return lop.content[i] > rop.content[i];
                }
            }
            return lop.Length > rop.Length;
        }
        static public bool operator <(String lop, String rop)
        {
            for (int i = 0; i < lop.Length && i < rop.Length; ++i)
            {
                if (lop.content[i] != rop.content[i])
                {
                    return lop.content[i] < rop.content[i];
                }
            }
            return lop.Length < rop.Length;
        }

        static private bool IsLower(byte b)
        {
            return b <= 'z' && b >= 'a';
        }
        static private bool IsUpper(byte b)
        {
            return b <= 'Z' && b >= 'A';
        }

        static private byte ToLower(byte b)
        {
            if (IsUpper(b))
            {
                return (byte)(b - 'A' + 'a');
            }
            else { return b; }
        }
        static private byte ToUpper(byte b)
        {
            if (IsLower(b))
            {
                return (byte)(b - 'a' + 'A');
            }
            else { return b; }
        }

        private void BuildNextArry()
        {
            if (nextArry == null)
            {

                nextArry = new int[Length];
                int j = 0;
                for (int i = 1; i < Length; ++i)
                {
                    while (j != 0 && content[j] != content[i])
                    {
                        j = nextArry[j - 1];
                    }
                    if (content[j] == content[i])
                    {
                        ++j;
                    }
                    nextArry[i] = j;
                }
            }

        }

        public String ToLower()
        {
            byte[] res = new byte[Length];
            for (int i = 0; i < Length; ++i)
            {
                res[i] = ToLower(content[i]);
            }
            return new String(res);
        }

        public String ToUpper()
        {
            byte[] res = new byte[Length];
            for (int i = 0; i < Length; ++i)
            {
                res[i] = ToUpper(content[i]);
            }
            return new String(res);
        }
        public String PrintRaw()
        {
            foreach (byte b in content)
            {
                Console.WriteLine(b);
            }
            return this;
        }
        public int FindFirstSubStrEq(String rop)
        {
            BuildNextArry();
            int j = 0;
            for (int i = 0; i < Length; ++i)
            {
                while (j != 0 && content[i] != rop.content[j])
                {
                    j = nextArry[j - 1];
                }
                if (content[i] == rop.content[j])
                {
                    ++j;
                }
                if (j == rop.Length)
                {
                    return i - j + 1;
                }
            }
            return -1;
        }
        public String Trim()
        {
            Stack<byte> stc = new Stack<byte>();
            foreach (byte b in content)
            {
                if (stc.Count != 0 || b != SPACE)
                {
                    stc.Push(b);
                }
            }
            while (stc.Peek() == SPACE)
            {
                stc.Pop();
            }
            byte[] bytes = stc.ToArray();
            Array.Reverse(bytes);
            return new String(bytes);
        }

        public String SubStr(int pos, int len)
        {
            if (len == NOPS || len + pos > Length)
            {
                len = Length - pos;
            }
            byte[] res = new byte[len];
            for (int i = 0; i < len; ++i)
            {
                res[i] = content[pos + i];
            }
            return new String(res);
        }

        public String Remove(int pos, int len)
        {
            if (len == NOPS || len + pos > Length)
            {
                len = Length - pos;
            }
            byte[] res = new byte[Length - len];
            int i = 0;
            for (; i < pos; ++i)
            {
                res[i] = content[i];
            }
            for (; i + len < Length; ++i)
            {
                res[i] = content[i + len];
            }
            return new String(res);
        }

        public String Replace(String other, int pos = 0, int len = NOPS)
        {
            if (len == NOPS || len > other.Length)
            {
                len = other.Length;
            }
            byte[] res = new byte[Math.Max(Length, pos + len)];
            int i = 0;
            for (; i < pos; ++i)
            {
                res[i] = content[i];
            }
            for (int j = 0; j < len; ++j, ++i)
            {
                res[i] = other.content[j];
            }
            for (; i < Length; ++i)
            {
                res[i] = content[i];
            }
            return new String(res);
        }
        public String Insert(String other, int pos = 0, int len = NOPS)
        {
            if (len == NOPS || len > other.Length)
            {
                len = other.Length;
            }
            byte[] res = new byte[Length + len];
            int i = 0;
            for (; i < pos; ++i)
            {
                res[i] = content[i];
            }
            for (int j = 0; j < len; ++j, ++i)
            {
                res[i] = other.content[j];
            }
            for (; i - len < Length; ++i)
            {
                res[i] = content[i - len];
            }
            return new String(res);
        }
        override public string ToString()
        {
            return Encoding.ASCII.GetString(content);
        }
    }
    class Program
    {
        static void Main(string[] _)
        {
            Console.WriteLine("Hello World!");
            Console.WriteLine(new String("Hello World!").FindFirstSubStrEq(new String("World")));
            Console.WriteLine(new String("Hello") > new String("World"));
            Console.WriteLine(new String("Hello") < new String("World"));
            Console.WriteLine(new String("Hello World!").Length);
            Console.WriteLine(new String("Hello World!").SubStr(5, String.NOPS));
            Console.WriteLine(new String("Hello World!").Remove(0, 5));
            Console.WriteLine(new String("Hello C!").Insert(new String("++"), 7));
            Console.WriteLine(new String("Hello C##!").Replace(new String("C++"), 6, 3));
            Console.WriteLine(new String("Hello World!").ToLower());
            Console.WriteLine(new String("Hello World!").ToUpper());
            Console.WriteLine(new String("Hello World!").Remove(0, 5).Trim());

        }
    }
}
