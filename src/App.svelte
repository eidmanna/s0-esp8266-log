<script>
   import TopAppBar, { Row, Section, Title } from '@smui/top-app-bar';
  import IconButton from '@smui/icon-button';
  
  import Button, { Label } from '@smui/button';

  let clicked = 0;
</script>

<main>

  <div class="top-app-bar-container">
    <TopAppBar
      variant="static"      
      color='primary'
    >
      <Row>
        <Section>
          <IconButton class="material-icons">menu</IconButton>
          <Title>Static</Title>
        </Section>
        <Section align="end" toolbar>
          <IconButton class="material-icons" aria-label="Download"
            >file_download</IconButton
          >
          <IconButton class="material-icons" aria-label="Print this page"
            >print</IconButton
          >
          <IconButton class="material-icons" aria-label="Bookmark this page"
            >bookmark</IconButton
          >
        </Section>
      </Row>
    </TopAppBar>
    <div>
      <div>
        <Button on:click={() => clicked++}>
          <Label>Default</Label>
        </Button>
      </div>     
    </div>
  </div>
  

 

  
</main>

<style>
  
</style>
