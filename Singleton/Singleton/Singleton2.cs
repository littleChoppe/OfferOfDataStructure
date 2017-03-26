using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    //虽然在多线程中工作，单效率不高，每次取实例都需要上锁
    class Singleton2
    {
        private Singleton2() { }

        private static readonly object synObj = new object();

        private static Singleton2 instance = null;
        public static Singleton2 Instance
        {
            get
            {
                lock(synObj)
                {
                    if (instance == null)
                        instance = new Singleton2();
                }
                return instance;
            }
        }
    }
}
