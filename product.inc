<?php
$username = isset($_SESSION['username'])?$_SESSION['username'] : "guess";
$product_list = get_product_list($producer);
$current_url = base64_encode("http://".$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']);
if($username != "guess"){
?>
<script type="text/javascript">
var product_list = {
	'PRODUCT CODE':{
		'name':'PRODUCT NAME',
		'price':'PRODUCT PRICE'
	}/* multidimentional array format */
<?php
foreach( $product_list as $each_product){
	echo ",'".$each_product['code']."':{";
	echo "'name':'".$each_product['name']."',";
	echo "'price':'".$each_product["price"]."'}";
}
?>
}

var background_colors = ['(229, 229, 229)','(51, 153, 204)','(247, 200, 14)'];
function click_add_to_cart(productID){
	document.getElementById('phone-name').innerHTML = product_list[productID]['name'];
	document.getElementById('phone-price').innerHTML = product_list[productID]['price'];
	document.getElementById('productid').value = productID;
	document.getElementById('productname').value = product_list[productID]['name'];
	document.getElementById('productprice').value = product_list[productID]['price'];	
	document.getElementById('product-add-to-cart').style.backgroundColor = "rgb"+background_colors[Math.floor(Math.random()*3)];
	Popup.show('product-add-to-cart','product'+productID,'center center',{'constrainToScreen':false});
}
function click_add_to_wish(productID){
	$.ajax({
        url: "backend.php",  
        type: "POST",
        data: {addToWishlistSubmitted:true,productID:productID},    
        cache: false,
        success: function(data) {  
			if (data=="1"){
				$('#popupmessage-txt').html("Successfully added to wishlist!");
				$('#popupmessage').css("background-color","rgb(146, 205, 0)");
			}
			else{
				$('#popupmessage-txt').html("This product is already inside in your wishlist");
				$('#popupmessage').css("background-color","rgb(247, 200, 14)");
			}
			Popup.show('popupmessage','product'+productID,'center center',{'constrainToScreen':false});
        }
    });
}
function click_add_to_favourite(productID){
	$.ajax({
        url: "backend.php",  
        type: "POST",
        data: {addToFavouriteSubmitted:true,productID:productID},    
        cache: false,
        success: function(data) {  
			data = JSON.parse(data);
			if (data['isFavourite']=="false"){
				document.getElementById('favourite'+productID).src = "images/gray-heart.png";
			}
			else{
				document.getElementById('favourite'+productID).src = "images/blue-heart.png";
			}
			document.getElementById('favourite-amount-'+productID).innerHTML = data['amount'];
        }
    });
}
</script>
<?php
}
?>
      <div class="product-list">
		<?php
			foreach( $product_list as $each_product){
		?>
  		  <table class="product-item" id="product<?php echo $each_product['code'];?>">
          <tr>
          	<td class="product-image"><img src="<?php echo $each_product["image"]?>" alt="Phone"/></td>
          	<td class="product-description">
          	<h1><?php echo $each_product["name"] ?></h1>
	        <p>Price: $<?php echo $each_product["price"];?></p>
			<a href="#" class="view">View More Details &gt;&gt;</a>
            </td>
          	<td class="product-buttons">
        	    <a href="#" class="add-cart" onclick="<?php echo $username=="guess"?"register":"click_add_to_cart";?>('<?php echo $each_product['code'];?>');">Add to Cart</a><br/>

	            <a href="#" class="wish-list" onclick="<?php echo $username=="guess"?"register":"click_add_to_wish";?>('<?php echo $each_product['code'];?>');">Add to Wish List</a><br/>
        	    <a href="#" class="favourite" onclick="<?php echo $username=="guess"?"register":"click_add_to_favourite";?>('<?php echo $each_product['code'];?>');">Favourite 	<br/>
                <img id="favourite<?php echo $each_product['code'];?>" src="images/<?php echo is_already_favourite($username,$each_product['code'])?"blue":"gray" ?>-heart.png" class="favouriteIcon" alt=""><span id="favourite-amount-<?php echo $each_product['code'];?>"><?php echo total_favourite_amount($each_product['code']); ?></span></a>
            </td>
          </tr>
          </table>
          <hr />
         <?php
			}
		 ?>

      </div>
<?php 
if($username != "guess"){
?>
<form action="cartupdate.php" method="post" id="dataform">
<input type="hidden" name="currentURL" value="<?php echo $current_url;?>" />
<input type="hidden" name="productID" id="productid" />
<input type="hidden" name="action" value="add" />
<input type="hidden" name="productName" id="productname"/>
<input type="hidden" name="price" id="productprice" />
<table id="product-add-to-cart">
<tr>
<td><b>Name</b></td><td><b>Price</b></td><td><b>Quantity</b></td><td rowspan="2"><input type="submit" value="Add to cart" /></td>
</tr>
<tr>
<td><span id="phone-name"></span></td><td>$&nbsp;<span id="phone-price"></span></td><td><select name="quantity">
<?php
for($i = 1; $i<=10; $i++){
	echo "<option value='".$i."'>".$i."</option>";
}
?>
</select>
</td>
</tr>
</table>
</form>
<?php
}
?>
<div id="popupmessage">
	<span id="popupmessage-txt"></span><br><br>
	<input type="button" value="OK" onClick="Popup.hide('popupmessage')">
</div>
<?php if($username == "guess"){ ?>
<script type="text/javascript">
var background_colors = ['(229, 229, 229)','(255, 174, 174)','(247, 200, 14)'];
function register(productID){
	$('#popupmessage-txt').html("Please Sign in or register!");
	$('#popupmessage').css('background-color','rgb'+background_colors[Math.floor(Math.random()*3)]);
	Popup.show('popupmessage','product'+productID,'center center',{'constrainToScreen':false});
}
</script>
<?php } ?>