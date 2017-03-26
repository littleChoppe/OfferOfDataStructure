using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    //只能在单线程内工作，在需要时才创建单例
    class Singleton1
    {
        private Singleton1()
        { }

        private static Singleton1 instance = null;
        public static Singleton1 Instance 
        {
            get 
            {
                if (instance == null)
                    instance = new Singleton1();
                return instance;
            }
        }
    }
}
