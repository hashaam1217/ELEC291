/* bug 460010
 */
#include "../fwk/include/testfwk.h"

#ifdef __C51
#ifdef __C51_pic16
#define ADDRESS 0x0070
#else
#define ADDRESS 0xa000
#endif  /* C51_pic16 */
#endif  /* C51 */

void 
func (unsigned char a)
{
  UNUSED (a);
}

void
testBadPromotion (void)
{
#ifdef __C51
  unsigned char c = *((unsigned __xdata char*)(ADDRESS));
#else
  unsigned char loc_c;
  unsigned char c = *(unsigned char*)&loc_c;
#endif 

  func (c);

  c += '0';     /* is evaluated as an 8-bit expr */ 

  func (c); 

  c += 'A'-'0'; /* is a 16-bit expr ??? */ 

  func (c);
}
