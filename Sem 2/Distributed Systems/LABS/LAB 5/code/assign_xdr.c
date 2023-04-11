/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "assign.h"

bool_t
xdr_numb (XDR *xdrs, numb *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_calc (XDR *xdrs, calc *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->c))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_arr (XDR *xdrs, arr *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  200 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->ar, 200,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->len))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->ar;
					i < 200; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->len);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  200 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->ar, 200,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->len))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->ar;
					i < 200; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->len = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->ar, 200,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->len))
		 return FALSE;
	return TRUE;
}
