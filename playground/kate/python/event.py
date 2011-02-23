
class Event:
    m_consumer = 0
    m_current = 0
    m_time = 0
    m_voltage = 0
    def __str__(self):
        res = 'm_voltage: '+str(self.m_voltage)
        res += '\nm_current: '+str(self.m_current)
        res += '\nm_current: '+str(self.m_consumer)
        res += '\nm_time: '+str(self.m_time)
        return res

    def print_info(self):
        print 'm_consumer = ',self.m_consumer
        print 'm_current = ',self.m_current
        print 'm_time  = ',self.m_time
        print 'm_voltage = ',self.m_voltage  

e = Event() 
print '1:'
print e
print '2:'
e.print_info()


