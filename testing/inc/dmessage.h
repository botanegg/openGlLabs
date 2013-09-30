#ifndef _DMESSAGE_H
#define _DMESSAGE_H

#ifdef DEBUG
    
    
    #include <iostream>
    
    #define _DEBUG_COUT(x) std::cout << x << std::endl;
    
    
#else /* DEBUG */

//empty macros
#define _DEBUG_COUT(x)

#endif

#endif /* _DMESSAGE_H */
