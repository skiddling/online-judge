+ 1.写的代码要能够方便调试，能够方便看到调试结果，当然也包括能够方便输出当中程序信息
+ 2.当不能确保直接写出性能极佳的代码的时候我们就要求写的代码要用人正常的运算方式和顺序，比如7e当中的循环顺序是看着是倒着来的，但是从递归的bottom-up的实现运算的角度来说却是按照人的正常运算符方向从左到右逐步进行的
+ 3.注意递归的先后顺序，在7e当中我们现实递归左子树，然后再递归到右子树，这样子能更方便的检查运算顺序和调试代码
+ 4.又对scanf当中的参数和使用有了新的认识
+ 5.对于要写的代码心中要有计算的模型的规划，就好比你确认一个问题是用线性的执行顺序去解决还是用树形的计算顺序去解决，线性的要注意各种边界问题，树形的递归则是要注意递归的出口，递归的顺序（哪个分支先进性递归），因为递归是一种top-down，然后bottom-up的顺序，所以实际当中先被计算的反倒是最后被递归到的，然后再逐步返回来，也就是父节点是在子节点计算完成之后才返回来的，整个的计算过程自己要有很清晰的概念和顺序