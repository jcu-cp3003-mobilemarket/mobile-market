<?php
session_start();
function connect_to_db()
  {
	  include("databasesetup.inc");
      @$db = mysqli_connect($host, $user,$password,$database) ;
	  if($db->connect_errno){
		      echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	  }
      return $db;     
  }
function get_current_page_name(){
	$filename = basename($_SERVER['REQUEST_URI']);
	if($filename== trim($_SERVER['REQUEST_URI'],"/") || $filename == "index.php"||$filename=="?home"|| $filename=="index.php?home") return "home";
	if($filename== "index.php?apple" || $filename == "?apple") return "apple";
	if($filename== "index.php?samsung" || $filename == "?samsung") return "samsung";
	if($filename== "index.php?others" || $filename == "?others") return "others";
	if($filename== "index.php?feedback" || $filename == "?feedback") return "feedback";
	if($filename== "index.php?cart" || $filename == "?cart") return "cart";
	if($filename== "index.php?login" || $filename == "?login") return "login";
	if($filename== "index.php?myaccount" || $filename == "?myaccount") return "myaccount";
	if($filename== "index.php?daily" || $filename == "?daily") return "daily";
	if($filename== "index.php?payment" || $filename == "?payment") return "payment";
	if($filename== "index.php?wishlist" || $filename == "?wishlist") return "wishlist";
	if($filename== "index.php?register" || $filename == "?wishlist") return "register";
	if($filename== trim($_SERVER['REQUEST_URI'],"/") || $filename == "admin.php"|| $filename=="admin.php?dashboard") return "dashboard";
	if($filename== "admin.php?contact" || $filename == "?contact") return "contact";
	if($filename== "admin.php?announcement" || $filename == "?announcement") return "announcement";
	if($filename== "admin.php?calendar" || $filename == "?calendar") return "calendar";
	if($filename== "admin.php?images" || $filename == "?images") return "images";
	header("location:index.php");
}

function get_page_data($pagename){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM page_data WHERE pagename = '$pagename' ")){
		while($row = $result->fetch_array()){
			$arr['content'] = $row['content'];
			$arr['title'] = $row['title'];
		}
	}
	return $arr;
}
function update_page_data($pagename,$title,$content){
	global $db;
	$db->query("UPDATE page_data SET pagename='$title', content='$content' WHERE pagename = '$pagename'");
}
function get_product_list($manufacturer){
	global $db;
	$query = "SELECT * FROM product WHERE manufacturer = '$manufacturer'";
	if($manufacturer == "Others") $query = "SELECT * FROM product WHERE manufacturer <> 'Apple' AND manufacturer <> 'Samsung'";
	$arr = array();
	if($result = $db->query($query)){
		while($row = $result->fetch_array()){
			$temp['code'] = $row['code'];
			$temp['name'] = $row['name'];
			$temp['price'] = $row['price'];
			$temp['image'] = $row['image'];
			$arr[] = $temp;
		}
	}

	return $arr;

}
function get_footer_data($title){
	global $db;
	if($result = $db->query("SELECT * FROM page_data WHERE title = '$title' AND pagename = 'footer' ")){
		while($row = $result->fetch_array()){
			return $row['content'];
		}
	}
}
function check_user_login($id,$pass){
	global $db;
	$pass = hash("sha256", $pass);
	if($result = $db->query("SELECT * FROM customer_login WHERE username = '$id' AND password = '$pass' ")){
		if($result->num_rows == 1) return true;
	}
	return false;
}
function check_cookie($id,$pass){
	if(check_user_login($id,$pass)){
		return $id;
	}
	return "guess";
}
function is_username_exist($username){
	global $db;
	if($result = $db->query("SELECT * FROM customer_login WHERE username = '$username'")){
		return $result->num_rows==0?false:true;
	}
	return true;
}
function is_email_exist($email){
	global $db;
	if($result = $db->query("SELECT * FROM customer_data WHERE email = '$email'")){
		return $result->num_rows!=0?true:false;
	}
	return true;
}
function add_new_customer($username,$password,$email){
	global $db;
	$password = hash("sha256", $password);
	$db->query("INSERT INTO `customer_login`(`username`, `password`) VALUES ('$username','$password')");
	$db->query("INSERT INTO `customer_data`(`username`, `email`) VALUES ('$username','$email')");
}
function remove_old_customer($username){
	global $db;
	$db->query("DELETE FROM `customer_login` WHERE username = '$username'");
	$db->query("DELETE FROM `customer_data` WHERE username = '$username'");
	$db->query("DELETE FROM `favourite` WHERE id = '$username'");
	$db->query("DELETE FROM `wishlist` WHERE id = '$username'");
	$db->query("DELETE FROM `coupon` WHERE id = '$username'");
}
function get_customer_data($username){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM customer_data WHERE username = '$username'")){
		while($row = $result->fetch_array()){
			$arr['firstname']= $row['firstname'];
			$arr['lastname']= $row['lastname'];
			$arr['gender']= $row['gender'];
			$arr['dob']= $row['dob'];
			$arr['contact']= $row['contact'];
			$arr['postalcode']= $row['postalcode'];
			$arr['address']= $row['address'];
			$arr['email']= $row['email'];
		}
	}
	return $arr;
}
function update_customer_data($id,$fn,$ln,$g,$d,$ph,$zip,$add){
	global $db;
	$db->query("UPDATE customer_data SET firstname ='$fn',lastname='$ln',dob='$d',gender='$g',contact='$ph',postalcode='$zip',address='$add' WHERE username = '$id'");
}

function update_customer_email($id,$email){
	global $db;
	$db->query("UPDATE customer_data SET email = '$email' WHERE username = '$id'"); 
}

function get_coupon($id){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM `coupon` WHERE id = '$id'")){
		while($row = $result->fetch_array()){
			$arr['green'] = $row['green'];
			$arr['blue'] = $row['blue'];
			$arr['yellow'] = $row['yellow'];
			$arr['token'] = $row['token'];
		}
	}
	return $arr;
}
function set_token($id,$token){
	global $db;
	$result = $db->query("UPDATE `coupon` SET token = '$token' WHERE id = '$id'");
}
function add_coupon($id,$coupon){
	global $db;
	$value = 0;
	if($coupon == "gray") return;
	if($result = $db->query("SELECT * FROM `coupon` WHERE id = '$id'")){
		while($row = $result->fetch_array()){
			$value = (int) $row[$coupon];
		}
		$value ++;
		$db->query("UPDATE `coupon` SET $coupon = '$value' WHERE id= '$id'");
	}
}
function request_to_show_sidebar_cart(){
	if(isset($_SESSION['cart']) && count($_SESSION['cart'])!=0  && get_current_page_name() != "cart"  && get_current_page_name() != "payment"){
		return true;
		}
	return false;
}
function get_product_info_by_id($id){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM `product` WHERE code = '$id'")){
		while($row = $result->fetch_array()){
			$arr['name'] = $row['name'];
			$arr['price'] = $row['price'];
			$arr['review'] = $row['review'];
			$arr['manufacturer'] = $row['manufacturer'] ;
			$arr['image'] = $row['image'];
		}
	}
	return $arr;	
}
function add_to_wishlist($id,$code){
	global $db;
	if($result = $db->query("SELECT * FROM `wishlist` WHERE id = '$id' AND product = '$code'")){
		if($result->num_rows >=1){
			die($result->num_rows);
			return false;
		}
		if($db->query("INSERT INTO `wishlist`(`id`, `product`) VALUES ('$id','$code')")){
			return true;
		}
	}
	return false;
}
function remove_from_wishlist($id,$code){
	global $db;
	$db->query("DELETE FROM `wishlist` WHERE id = '$id' AND product='$code'");
}
function get_wishlist($id){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM `wishlist` WHERE id = '$id'")){
		while($row = $result->fetch_array()){
			$arr[] = $row['product'];
		}
	}
	return $arr;
}
function is_already_favourite($id,$code){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM `favourite` WHERE id='$id' AND code = '$code'")){
		if($result->num_rows == 1){
			return true;
		}
	}
	return false;
}
function add_to_favourite($id,$code){
	global $db;
	$result = $db->query("INSERT INTO `favourite`(`id`, `code`) VALUES ('$id','$code')");
}
function remove_from_favourite($id,$code){
	global $db;
	$result = $db->query("DELETE FROM `favourite` WHERE id = '$id' AND code= '$code'");
}
function total_favourite_amount($code){
	global $db;
	$arr = array();
	if($result = $db->query("SELECT * FROM `favourite` WHERE code = '$code'")){
		return $result->num_rows;
	}
	return 0;
}
function add_to_dailychance($id){
	global $db;
	$today = date("Y-m-d H:i:s",time() - 60*60*24);
	$db->query("INSERT INTO `coupon`(`id`, `green`, `blue`, `yellow`, `token`) VALUES ('$id','0','0','0','$today')");
}
function remove_from_dailychance($id){
	global $db;
	$db->query("DELETE FROM `coupon` WHERE id = '$id'");
}
$db = connect_to_db();
date_default_timezone_set('Asia/Singapore');
$username = isset($_SESSION['username'])?$_SESSION['username'] : (isset($_COOKIE['username'])?check_cookie($_COOKIE['username'],$_COOKIE['password']):"guess");
?>