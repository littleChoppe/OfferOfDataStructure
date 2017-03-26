using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    //实现按需创建
    //Nested在第一次调用之前才会调用静态构造函数然后对静态成员赋值
    //所以只有调用单例的实例时，才会创建实例，并不会浪费空间
    //实现了按需创建
    class Singleton5
    {
        Singleton5() { }

        public static Singleton5 Instance
        {
            get { return Nested.instance; }
        }
        class Nested
        {
            //static Nested() { }

            internal static readonly Singleton5 instance = new Singleton5();
        }
    }
}
