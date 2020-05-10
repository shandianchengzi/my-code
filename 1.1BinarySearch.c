Position BinarySearch( List L, ElementType X )
{
    Position right=L->Last,left=1,middle=(right+left)/2;
    while(left<right)
    {
        if(L->Data[middle]>X)
        {
            right=middle-1;
            middle=(right+left)/2;
        }
        else if(L->Data[middle]<X)
        {
            left=middle+1;
            middle=(right+left)/2;
        }
        else
            return middle;
    }
    if(L->Data[middle]==X)
    	return middle;
    else
    	return NotFound;
}
