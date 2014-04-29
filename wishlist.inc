<?php
if($username=="guess" ){
	header("location:index.php");
}
$wish_list_code = get_wishlist($_SESSION['username']);
if(count($wish_list_code)>0){
$rotate = array('rotate5','rotate-5','rotate10','rotate-10');
$note_color = array('red-note','blue-note','purple-note','brown-note','green-note','gray-note');
?>

<div class="wishlist">
<?php
$i = 0;
foreach($wish_list_code as $each_code){
	$product_info = get_product_info_by_id($each_code);
	$product_info['name'];
?>
	<div id="product<?php echo $each_code;?>" class="sticky-note yello-note <?php echo $rotate[rand(0,3)]." ".$note_color[$i++%6];?>" ><img src="images/pin.png" class="pin" alt="" onclick="removeFromWishlist('<?php echo $each_code;?>')"/>
    	<h1><?php echo $product_info['name']?></h1>
		<img src="<?php echo $product_info['image'];?>" alt="<?php echo $product_info['name']?>" class="thumbnail" />
        <h2>$ <?php echo $product_info['price'];?></h2>
	</div>	
	
<?php
}
?>
</div>
<script type="text/javascript">
function removeFromWishlist(id){
	document.getElementById('product'+id).className = document.getElementById('product'+id).className+" tear-note";
	$.ajax({
	url: "backend.php",  
	type: "POST",
	data: {removeFromWishlistSubmitted:true,code:id},    
	cache: false,
	success: function(data){
		document.getElementById('product'+data).style.display = "none"
	}
    });
}
</script>
<?php
}
else{
?>
<div style="position:relative;top:200px;margin-left:auto;margin-right:auto; width:300px; margin-top:0px;">
<img src="images/empty-note.png" alt="No item"  />
</div>
<?php
}
?>