<?php
//check ajax request
if (!isset($_SERVER['HTTP_X_REQUESTED_WITH'])){
		die();
}
require("databaseconnect.inc");
if(isset($_POST['loginFormSubmitted']) && isset($_POST['username']) && isset($_POST['password'])){
	$username = $_POST['username'];
	$password = $_POST['password'];
	$remembere = $_POST['rememberme'];
	if(check_user_login($username,$password)){
		$_SESSION['username'] = $username;
		if($remembere == "true"){
			setcookie("username", $username, time()+60*60*24*30*12);
			setcookie("password", $password, time()+60*60*24*30*12);
			}
		echo "true";
	}
	else{
		echo "false";
	}
}
if(isset($_POST['TokenFormSubmitted'])){
	if(isset($_POST['token'])){
		set_token($_SESSION['username'],$_POST['token']);
	}
	if(isset($_POST['type'])){
		add_coupon($_SESSION['username'],$_POST['type']);
	}
	$arr = get_coupon($_SESSION['username']);
	echo json_encode($arr);
	unset($arr);
}
if(isset($_POST['checkValidEmailSubmitted'])){
	if(is_email_exist($_POST['email'])){
		echo $_POST['email']." is already used.";
	}
	else{
		echo "success";
	}
}
if(isset($_POST['userNameValidateFormSubmitted'])){
	if(is_username_exist($_POST['username']) || ($_POST['username'] == "guess")){
		echo "'".$_POST['username']."' is not avaliable";
	}
	else{
		echo "Avaliable";
	}
}
if(isset($_POST['regiserFormSubmitted']) && isset($_POST['username']) && isset($_POST['password'])){
	if(!is_username_exist($_POST['username']) && !is_email_exist($_POST['email'])){
		add_new_customer($_POST['username'],$_POST['password'],$_POST['email']);
		add_to_dailychance($_POST['username']);
		session_regenerate_id();
		$_SESSION['username'] = $_POST['username'];
		echo "success";
	}
}
if(isset($_POST['addToWishlistSubmitted']) && isset($_SESSION['username']) && isset($_POST['productID'])){
	if(add_to_wishlist($_SESSION['username'],$_POST['productID'])){
		echo "1";
	}
	else{
		echo "0";
	}
}
if(isset($_POST['removeFromWishlistSubmitted'])&& isset($_POST['code'])){
	remove_from_wishlist($_SESSION['username'],$_POST['code']);
	echo $_POST['code'];
}
if(isset($_POST['addToFavouriteSubmitted']) && isset($_SESSION['username']) && isset($_POST['productID'])){
	$arr=array();
	if(is_already_favourite($_SESSION['username'],$_POST['productID'])){
		remove_from_favourite($_SESSION['username'],$_POST['productID']);
		$arr["isFavourite"] = "false";
	}
	else{
		add_to_favourite($_SESSION['username'],$_POST['productID']);
		$arr['isFavourite'] = "true";
	}
	$arr['amount'] = total_favourite_amount($_POST['productID']);
	echo json_encode($arr);
	unset($arr);
}
if(isset($_POST['FeedbackEdited'])){
	update_page_data('feedback','feedback',$_POST['text']);
	$arr = get_page_data('feedback');
	echo $arr['content'];
	unset($arr);

}
if(isset($_POST['oldURL']) && isset($_FILES['newURL'])){
	if(isset($_FILES["newURL"]) && $_FILES["newURL"]["error"]== UPLOAD_ERR_OK){
	$UploadDirectory	= 'images/';
	if ($_FILES["newURL"]["size"] > 5242880) {
		die("File size is too big!");
	}
	$file_name  = $_FILES['newURL']['name'];
	switch(strtolower($_FILES['newURL']['type'])){
			case 'image/gif': 
				if(move_uploaded_file($_FILES['newURL']['tmp_name'], $UploadDirectory.$file_name )){
					   $img = imagecreatefromgif($UploadDirectory.$file_name);
				}
				else{
					die('Error uploading File!');
				}
				break;
			case 'image/jpeg': 
			case 'image/pjpeg':
			case 'image/pjpg':
			case 'image/jpg':
				if(move_uploaded_file($_FILES['newURL']['tmp_name'], $UploadDirectory.$file_name )){
					   $img = imagecreatefromjpeg($UploadDirectory.$file_name);
				}
				else{
					die('Error uploading File!');
				}
				break;
			case 'image/png': 
				if(move_uploaded_file($_FILES['newURL']['tmp_name'], $_POST['oldURL'])){
					die("success");
				}else{
					die('Error uploading File!');
				}
			default:
				die('Unsupported File!'); //output error
	}
	if(imagepng($img,$_POST['oldURL'])){
		unlink($UploadDirectory.$file_name);
		die("success");
	}
	else{
		unlink($UploadDirectory.$file_name);
		die("Error cannot convert to png format");
	}
	echo "Unknown error!";
	}
	else{
		die('Something wrong with upload! Is "upload_max_filesize" set correctly?');
	}
}
if(isset($_POST['EventObjectSubmitted'])){
	if(isset($_POST['add'])){
		 add_new_event($_POST['id'],$_POST['title'],$_POST['start'],$_POST['end'],$_POST['allday'],$_POST['color']);
	}
	else if(isset($_POST['update'])){
		update_event($_POST['id'],$_POST['start'],$_POST['end'],$_POST['allday']);
	}
	else if(isset($_POST['remove'])){
		remove_event($_POST['id']);
	}	

}
if(isset($_POST['EventNotification'])){
	$events = get_event_data();
	$today = strtotime("now");
	foreach($events as $event){
		 if(strtotime($event['start'])<=$today){
			 echo $event['title'];
		 }
	}
}
?>