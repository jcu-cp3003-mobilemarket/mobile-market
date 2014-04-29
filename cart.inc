<?php
if($username=="guess" ){
	header("location:index.php");
} 
if( isset( $_SESSION['cart']) && count($_SESSION['cart']) > 0) {
?>
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

			<div class="shopping-cart">
           
				<?php
				$cart_bg_color = array("cart-blue-bg","cart-yellow-bg","cart-green-bg","cart-gray-bg");
				$i = 0;
                $total = 0;
                foreach($cart as $id=>$each_item){
                    $total += $each_item['price']*$each_item['qty'];
					echo "<table  class=\"cart-item ".$cart_bg_color[($i++)%4]."\"><tr>";
					echo "<td class='smallwidth'>$i.</td>";
                    echo "<td class='largewidth'>".$each_item['name'] ."</td>";
					echo "<td class='mediumwidth'>$".$each_item['price']."</td>";
					echo "<td class='mediumwidth'>x".$each_item['qty']."</td>";
					echo "<td class='right-align mediumwidth'> = ".($each_item['qty']*$each_item['price'])."</td>";
                    echo "<td class='right-align smallwidth'><img src='images/remove-from-cart.png' alt='Remove from cart' onclick=\"click_remove_from_cart('".$id."')\"/></td>";
					echo "</tr></table>";
                }
                ?>
                <span class="cart-green-bg extra-amount"></span><span class="cart-green-bg extra-amount"> 
                <select><option>Standard Shipping</option><option>Express Shipping</option></select>
                </span><br /><br/><br/>
                <span class="cart-green-bg extra-amount"></span><span class="cart-green-bg extra-amount">Discount</span><br /><br/><br/>
                <span class="cart-blue-bg extra-amount">= $<?php echo $total?></span><br/><br/><br/>
                <form action="?payment" method="post">
                <input type="hidden" name="total" value="<?php echo $total?>" />
                <input type="hidden" name="currentURL" value="<?php echo base64_encode("http://".$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']);?>" />
                <input type="submit" value="Payment" />
                <input type="text" required="required" pattern="[0-9]*" placeholder="123456" name="contact" value="" required="required"/><br />
                <input type="text" required="required" pattern="[0-9]*" placeholder="123456" name="contact" value="" required="required"/><br />
                <textarea placeholder="Enter your Address" required="required"></textarea>
                <input type="hidden" name="address" id="address"/>
                </form>

            </div>
<?php 
	}
	else{
?>
<div style="position:relative;top:200px;margin-left:auto;margin-right:auto; width:300px; margin-top:0px;">
<img src="images/empty-cart.png" alt="No item"  />
</div>
<?php
	}
?>