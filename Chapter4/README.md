## uva253
<p>打表就完事了……</p>
<p>trans的作用：行代表1轴在第二个串中是几轴，列代表2轴在第二个串中是几轴，trans[i][j]代表3轴在第二串中一定是几轴</p>
<p>这样就把三个面的相对位置确定了</p>
<p>//听说有代码简单判定同轴上面的字母就AC了，那只能说数据太水了，不然可以试试gbbrgrgbrbgr</p>

## uva1590
<p>找到第一个不同的位置：异或</p>
<p>无符号数低n位清零：(a >> n) << n</p>
<p>我用的清零方法都是移位运算，这就导致了在左移32位的时候，机器会什么也不做</p>
<p>当移动的位数大于或等于该数据类型位数时，CPU对移动的位数进行基于数据类型位数的取余运算，余数为实际移动的位数。比如uint32_t类型左移32位，实际移动0位，也就是数字保持不变；左移33位，则实际左移1位。</p>

## uva1591
<p>这道题没给A，B范围把我坑惨了，一直在草稿上不断变形打算找范围……上网查博客才知道n和S_q的范围是有用的</p>
<p>由于1<=n<=2^20，1<=S_q<=2^10，而题目要找的K是一个比n*S_q<=2^30稍大的数，所以a,b都在0~31范围内（说是这么说……）</p>
<p>有了范围那自然是暴力完事</p>
