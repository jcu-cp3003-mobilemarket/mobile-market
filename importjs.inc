<?php
$current_page_name = get_current_page_name();
$j_query_pages = array("home","apple","samsung","others","feedback","daily","myaccount","login","cart");
$popup_pages=array("apple","samsung","others");
foreach($j_query_pages as $page){
	if($page == $current_page_name){
		echo "<script type='text/javascript' src='http://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js'></script>";
		break;
	}
}
foreach($popup_pages as $page){
	if($page == $current_page_name){
		echo "<script type='text/javascript' src='js/popup.js'></script>";
	}
}
?>