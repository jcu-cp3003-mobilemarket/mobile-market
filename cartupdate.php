<?php
//cart = array('id1'=>('name','qty','price'),'id2'=>('name','qty','price'));
session_start();
  $return_url = base64_decode($_POST["currentURL"]); //return url
  if(isset($_POST['productID']) && isset($_POST['quantity'])){
	  $product_id = $_POST['productID'];
	  $product_qty = (int)$_POST['quantity'];
 
	  if(!isset($_SESSION['cart'])){
		  $cart = array();
	  }
	  else{
		  $cart = $_SESSION['cart'];
	  }
	  if(array_key_exists($product_id,$cart)){
		  if($_POST['action'] == "add"){
		  	$cart[$product_id]['qty'] = $cart[$product_id]['qty'] +$product_qty;
			$_SESSION['is_add_to_cart_success'] =true;
		  }
		  else{
			  $cart[$product_id]['qty'] = $cart[$product_id]['qty'] - $product_qty;
			  if($cart[$product_id]['qty']<1){
				  unset($cart[$product_id]);
			  }
			  $_SESSION['is_remove_from_cart_success'] =true;
		  }
	  }
	  else{
		  if($_POST['action'] == "add"){
			  $cart[$product_id]['name'] = $_POST['productName'];
			  $cart[$product_id]['qty'] = $product_qty;
			  $cart[$product_id]['price'] = (int)$_POST['price'];
			  $_SESSION['is_add_to_cart_success'] =true;
		  }
		  else{
			    header('Location:index.php');
		  }
	  }
	  $_SESSION['cart']=$cart;
	  ksort($_SESSION['cart']);
  }
  header('Location:'.$return_url);
?>