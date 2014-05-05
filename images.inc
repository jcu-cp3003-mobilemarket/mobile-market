<?php
$imagedatalist = array(
		array('id'=>'logo','class'=>'','description'=>'Show in the navigation menubar (92x85)'),
		array('id'=>'homepagepic','class'=>'','description'=>'Show in the Home page (450x425)'),
		array('id'=>'call','class'=>'transparent-grid sm-img','description'=>'Show in the footer(35x35 with transparent background)'),
		array('id'=>'feedback','class'=>'transparent-grid sm-img','description'=>'Show in the footer (35x35 with transparent background)'),
		array('id'=>'follow','class'=>'transparent-grid sm-img','description'=>'>Show in the footer (35x35 with transparent background)'),
		array('id'=>'fb','class'=>'transparent-grid sm-img','description'=>'Show in the facebook link (25x25)'),
		array('id'=>'g-plus','class'=>'transparent-grid sm-img','description'=>'Show in the google+ link (25x25)'),
		array('id'=>'twitter','class'=>'transparent-grid sm-img','description'=>'Show in the twitter link (25x25)'),
		array('id'=>'cart','class'=>'transparent-grid','description'=>'Show in the sidebar cart (100x43)'),
		array('id'=>'blue-coupon','class'=>'transparent-grid sm-img','description'=>'Show in daily chance (100x100)'),
		array('id'=>'green-coupon','class'=>'transparent-grid sm-img','description'=>'Show in daily chance (100x100)'),
		array('id'=>'yellow-coupon','class'=>'transparent-grid sm-img','description'=>'Show in daily chance (100x100)'),
	);

?>

<table class="image-setting">
<tr>
<th>Original Image</th><th class="max-300px">Description with recomended dimensions</th><th>New Image</th>
</tr>
<?php
foreach($imagedatalist as $eachimage){
?>
<tr><td><img id="<?php echo $eachimage['id']?>img" src="images/<?php echo $eachimage['id']?>.png" class="<?php echo $eachimage['class']?>"/></td><td><?php echo $eachimage['description']?></td><td><input type="file" id="<?php echo $eachimage['id']?>" /><input type="button" onclick="updateimage('<?php echo $eachimage['id']?>')" value="Update" class="float-right"  /></td></tr>
<?php
}
?>
</table>
<div id='overlay'></div>
</form>
<script type="text/javascript">
function updateimage(img){
	var oldurl = 'images/'+img+'.png';	
	var inputElement = document.getElementById(img).files;
	var fdata = new FormData();
	fdata.append('newURL',inputElement[0]);
	fdata.append('oldURL',oldurl);
	$.ajax({
	  type: 'POST',
	  url: 'backend.php',
	  data: fdata,
      async: false,
      cache: false,
      contentType: false,
      processData: false,
	  complete: function(){
		  $('#'+img+'img').attr('src',oldurl).delay(10);
		  $('#'+img+'').val('');
		  }
	});
	
}
</script>