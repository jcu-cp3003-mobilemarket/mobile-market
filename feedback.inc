<?php
$feedback = get_page_data("feedback");
?>
      <div class="page-content">
        <h1>
        	<?php echo $feedback['title']; ?>
        </h1>

        <hr/>
        <p>	<?php echo $feedback['content']?></p>
        <form name="" class="feedback">
        <table>
        <tr>
        	<td><input type="text" placeholder="Name"></td>
            <td rowspan="3"><textarea placeholder="Message"></textarea></td>
        </tr>
        <tr>
            <td><input type="text" placeholder="Email"></td>
        </tr>
        <tr>
        
            <td><input type="text" placeholder="Subject"></td>
        </tr>
        <tr>
        	<td colspan="2" class="feedback-submit"><a href="#">Send</a></td>
        </tr>
        <tr>
        	<td colspan="2">
            
            	<a href="<?php echo get_footer_data("facebook")?>"><img class="social-share" src="images/fb.png" alt=""/></a>
                <a href="<?php echo get_footer_data("g-plus")?>"><img class="social-share" src="images/g-plus.png" alt=""/></a>
                <a href="<?php echo get_footer_data("twitter")?>"><img class="social-share" src="images/twitter.png" alt=""/></a>
                <br/><br/>
                <b>Cell</b> : 123-456-7890<br/>
				﻿<b>Email</b> : info@mysite.com

            </td>
        </tr>
       </table>
        </form>

      </div>

