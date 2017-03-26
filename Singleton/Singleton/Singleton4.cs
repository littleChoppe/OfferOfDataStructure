using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    //运用此方法，静态成员赋值系统会自动生成一个静态构造函数
    //在调用此类之前系统会自动调用此类的静态构造函数并只调用一次，所以只会生成一个实例
    //但是这个方法是不管需不需要实例都会存储一个实例，并不能控制实例的生成，所以会浪费空间
    class Singleton4
    {
        private Singleton4() { }

        private static Singleton4 instance = new Singleton4();
        public static Singleton4 Instance
        {
            get { return instance; }
        }
    }
}
