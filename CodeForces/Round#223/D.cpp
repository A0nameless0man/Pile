//the global data are integer arrays cnt[], left[][], right[][]

cnt[1] = 1;
fill arrays left[][], right[][] with values -1;
for(level = 1; level < n; ++level)
{
    cnt[level + 1] = 0;
    for(position = 1; position <= cnt[level]; ++position)
	{
        if(the value of position is a power of two)
		{ // that is, 1, 2, 4, 8...
            left[level][position] = cnt[level + 1] + 1;
            right[level][position] = cnt[level + 1] + 2;
            cnt[level + 1] += 2;            
        }
		else
		{
            right[level][position] = cnt[level + 1] + 1;
            cnt[level + 1] += 1;
        }
    }
}
