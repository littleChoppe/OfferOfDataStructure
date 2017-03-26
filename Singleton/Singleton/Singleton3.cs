using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    //只有第一次创建时才会上锁，以后就直接返回单例,但是仍然要上锁，消耗性能
    class Singleton3
    {
        private Singleton3() { }

        private static readonly object synObj = new object();

        private static Singleton3 instance = null;
        public static Singleton3 Instance
        {
            get
            {
                if (instance == null)
                {
                    lock(synObj)
                    {
                        if (instance == null)
                            instance = new Singleton3();
                    }
                }
                return instance;
            }
        }
    }
}
