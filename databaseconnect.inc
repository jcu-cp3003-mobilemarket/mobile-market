<?php
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
function get_product_list($manufacturer){
	global $db;
	$query = "SELECT * FROM product WHERE manufacturer = '$manufacturer'";
	if($manufacturer == "Others") $query = "SELECT * FROM product WHERE manufacturer <> 'Apple' AND manufacturer <> 'Samsung'";
	$arr = array();
	if($result = $db->query($query)){
		while($row = $result->fetch_array()){
			$temp['name'] = $row['name'];
			$temp['price'] = $row['price'];
			$temp['image'] = $row['image'];
			$temp['favourite'] = $row['favourite'];
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

$db = connect_to_db();
date_default_timezone_set('Asia/Singapore');
?>
