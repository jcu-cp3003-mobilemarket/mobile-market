<script type="text/javascript">
var cart_list = {
	'PRODUCT CODE':{
		'name':'PRODUCT NAME',
		'price':'PRODUCT PRICE',
		'qty':'PRODUCT QUANTITY'
	}
	/* multidimentional array format */
<?php
$cart = $_SESSION['cart'];
foreach($cart as $id => $each_item){
	echo ",'".$id."':{";
	echo "'name':'".$each_item['name']."',";
	echo "'price':'".$each_item["price"]."',";
	echo "'qty':'".$each_item['qty']."'}";
}
?>
}
var background_colors = ['(229, 229, 229)','(51, 153, 204)','(247, 200, 14)'];

function click_remove_from_cart(productID){
	var selectbox = document.getElementById('remove-qty-select');
	selectbox.options.length = 0;
	for(var i=1; i<=parseInt(cart_list[productID]['qty']);i++){
		selectbox.options[selectbox.options.length] = new Option(i,i);
	}
	document.getElementById('remove-phone-name').innerHTML = cart_list[productID]['name'];
	document.getElementById('remove-phone-price').innerHTML = cart_list[productID]['price'];	
	document.getElementById('removeid').value = productID;
	document.getElementById('product-remove-from-cart').style.backgroundColor = "rgb"+background_colors[Math.floor(Math.random()*3)];		
	Popup.show('product-remove-from-cart');
}
</script>
<form action="cartupdate.php" method="post">
<input type="hidden" id="removeid" name="productID" />
<input type="hidden" name="currentURL" value="<?php echo base64_encode("http://".$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']);?>" />
<table id="product-remove-from-cart">
<tr>
<td><b>Name</b></td><td><b>Price</b></td><td><b>Quantity</b></td><td rowspan="2"><input type="submit" value="Remove from cart" /></td>
</tr>
<tr>
<td><span id="remove-phone-name"></span></td><td>$&nbsp;<span id="remove-phone-price"></span></td><td><select name="quantity" id="remove-qty-select">
<option></option>
</select>
</td>
</tr>
</table>
</form>
<div class="side-show-cart" id="cart-image-sidebar">
<img src="images/cart.png" alt="Show Cart" />
</div>
<div class="side-hidden-cart" id="hidden-cart" >
<u>Your Cart</u><br /><br />
<table>
<?php
$total = 0;
foreach($cart as $id=>$each_item){
	$total += $each_item['price']*$each_item['qty'];
	echo "<tr><td>".$each_item['name'] ."</td><td>x".$each_item['qty']."</td><td>=$".($each_item['price']*$each_item['qty'])."</td>";
	echo "<td><img src='images/remove-from-cart.png' alt='Remove from cart' onclick=\"click_remove_from_cart('".$id."')\"/></td></tr>";
}
?>
<tr>
<td colspan="2">Total</td>
<td colspan="2">=$<?php echo $total;?></td>
</tr>
</table>
<a href="?cart">Checkout</a>
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
<?php
if(isset($_SESSION['is_remove_from_cart_success']) && $_SESSION['is_remove_from_cart_success'] == true){
	$popupbgcolor = "rgb(247, 200, 14)";
	$popupmessage = "Successfully removed from cart!";
	include("addcartpopupmessage.inc");
	$_SESSION['is_remove_from_cart_success'] = NULL;
	unset($_SESSION['is_remove_from_cart_success']);
}

?>