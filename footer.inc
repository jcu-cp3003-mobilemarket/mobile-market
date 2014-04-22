<?php
?>
<footer>
<div class="footer-item">
  <div>
    <img src="images/call.png" alt="">
  </div>	<strong>Call</strong>

  <br><?php echo get_footer_data("Call"); ?>
  
  </div>
<div class="footer-item">
  <div>
    <img src="images/feedback.png" alt="">
  </div>	<strong>Contact</strong>

  <br><?php echo get_footer_data("Contact"); ?>
  </div>
<div class="footer-item">
  <div>
    <img src="images/follow.png" alt="">
  </div>	<strong>Follow me</strong><br/>
<a href="<?php echo get_footer_data("facebook"); ?>" target="_blank"><img src="images/fb.png" alt="" /></a>
<a href="<?php echo get_footer_data("g-plus"); ?>" target="_blank"><img src="images/g-plus.png" alt="" /></a>
<a href="<?php echo get_footer_data("twitter"); ?>" target="_blank"><img src="images/twitter.png" alt="" /></a>
</div>
</footer>    
<?php
$db->close();
?>