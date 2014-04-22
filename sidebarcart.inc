<?php
?>
<div class="side-show-cart" id="cart-image-sidebar">
<img src="images/cart.png" alt="Show Cart" />
</div>
<div class="side-hidden-cart" id="hidden-cart" >
<u>Your Cart</u><br /><br />
<table>
<tr>
<td>iPhone 5 </td>
<td>x1</td>
<td>=$1000</td>
</tr>
<tr>
<td>iPhone 5 </td>
<td>x1</td>
<td>=$1000</td>
</tr>
<tr>
<td>iPhone 5 </td>
<td>x1</td>
<td>=$1000</td>
</tr>
<tr>
<td>iPhone 5 </td>
<td>x1</td>
<td>=$1000</td>
</tr>
<tr>
<td>iPhone 5 </td>
<td>x1</td>
<td>=$1000</td>
</tr>
<tr>
<td colspan="2">Total</td>
<td>=$1000</td>
</tr>
</table>
<a href="#">Checkout</a>
</div>
<script type="text/javascript">
var isImgFlip=false;
$('#cart-image-sidebar').click(
	function(){
		if(isImgFlip){
			$('#hidden-cart').removeClass("show-cart"); 
			$('#hidden-cart').addClass("hide-cart"); 
			$('#cart-image-sidebar').removeClass("flip");
			isImgFlip = false;
		}
		else{
			$('#hidden-cart').removeClass("hide-cart"); 
			$('#hidden-cart').addClass("show-cart"); 
			$('#cart-image-sidebar').addClass("flip");
			isImgFlip = true;
		}
		}
	);
</script>
