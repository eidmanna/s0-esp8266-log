<script>
  import { onMount } from "svelte";
  import axios from "axios";
  import TopAppBar, { Row, Section, Title } from "@smui/top-app-bar";
  import IconButton from "@smui/icon-button";
  import CircularProgress from "@smui/circular-progress";
  import DataTable, { Head, Body, Row as RowT, Cell } from '@smui/data-table';

  let dataList;

  // set for development only !!!!!
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
    <p/>
    <div>
      <div>
        {#if dataList}
        <DataTable table$aria-label="People list" style="max-width: 100%;">
          <Head>
            <RowT>
              
              <Cell>Name</Cell>
              <Cell >Wert</Cell>
              <Cell >Einheit</Cell>
            </RowT>
          </Head>
          <Body>
            {#each dataList as data}
            <RowT>
              <Cell>{data.title}</Cell>
              <Cell>{data.value}</Cell>
              <Cell>{data.unit}</Cell>
            </RowT> 
            {/each}           
          </Body>
        </DataTable>

          
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
