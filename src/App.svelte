<script>
  import { onMount } from "svelte";
  import axios from "axios";
  import TopAppBar, { Row, Section, Title } from "@smui/top-app-bar";
  import List, { Item, Text, PrimaryText, SecondaryText } from "@smui/list";
  import IconButton from "@smui/icon-button";
  import CircularProgress from "@smui/circular-progress";

  import Button, { Label } from "@smui/button";

  let clicked = 0;

  let dataList;

  // let server = "http://192.168.0.89/data";

  let server = "/data";

  onMount(() => {
    loadData();
  });

  const loadData = () => {
    axios.get(server).then((response) => {
      console.log(response.data);
      dataList = response.data;
    });
  };
</script>

<main>
  <div class="top-app-bar-container">
    <TopAppBar variant="static" color="primary">
      <Row>
        <Section>
          <IconButton class="material-icons">menu</IconButton>
          <Title>Wärmepumpe</Title>
        </Section>
        <Section align="end" toolbar>
          <!-- <IconButton class="material-icons" aria-label="Download"
            >file_download</IconButton
          >
          <IconButton class="material-icons" aria-label="Print this page"
            >print</IconButton
          > -->
          <IconButton class="material-icons" aria-label="Bookmark this page"
            >bookmark</IconButton
          >
        </Section>
      </Row>
    </TopAppBar>
    <div>
      <div>
        {#if dataList}
          <List twoLine nonInteractive>
            {#each dataList as data}
              <Item>
                <Text>
                  <PrimaryText>{data.title}</PrimaryText>
                  <SecondaryText>{data.value + "[" + data.unit + "]"}</SecondaryText>                  
                </Text>
              </Item>
            {/each}
          </List>
        {:else}
          <div style="display: flex; justify-content: center">
            <CircularProgress
              style="height: 32px; width: 32px;"
              indeterminate
            />
          </div>
        {/if}
      </div>
    </div>
  </div>
</main>

<style>
</style>
