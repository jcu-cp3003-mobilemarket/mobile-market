<?php
$product_list = get_product_list($producer);
?>
<table id="product-add-to-cart">
<tr>
<td>Name</td><td>Price</td><td>Quantity</td><td rowspan="2"><input type="submit" value="Add to cart" /></td>
</tr>
<tr>
<td>Phone</td><td>1000</td><td><select><option>1</option></select></td>
</tr>
</table>

<a href="#" onclick="Popup.show('product-add-to-cart');return false;">Click Here To Show DIV</a>
      <div class="product-list">
		<?php
		$current_url = base64_encode("http://".$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']);
			foreach( $product_list as $each_product){
		?>
  		  <table class="product-item">
          <tr>
          	<td class="product-image"><img src="<?php echo $each_product["image"]?>" alt="Phone"/></td>
          	<td class="product-description">
          	<h1><?php echo $each_product["name"] ?></h1>
	        <p>Price: $<?php echo $each_product["price"];?></p>
			<a href="#" class="view">View More Details &gt;&gt;</a>
            </td>
          	<td class="product-buttons">
            <form action="cartupdate.php">
        	    <a href="#" class="add-cart">Add to Cart</a><br/>
            </form>
	            <a href="#" class="wish-list">Add to Wish List</a><br/>
        	    <a href="#" class="favourite">Favourite 	<br/>
                <img src="images/star.png" alt=""><?php echo $each_product['favourite']; ?></a>
            </td>
          </tr>
          </table>
          <hr />
         <?php
			}
		 ?>

      </div>